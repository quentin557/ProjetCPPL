#include "consolequoridor.h"
#include "keyboard.hpp"

ConsoleQuoridor::ConsoleQuoridor(Quoridor* game) : Observer(game) {
    update();
}

void ConsoleQuoridor::update()
{
    std::cout<<getGame()->to_string()<<std::endl;
}

void ConsoleQuoridor::placeWall(int playerNb){
    int x,y,size;
    bool hORv;
    std::string in;
    size = getGame()->getSize();
    std::cout << "Indiquez l'horizontale : ";
    x = nvs::lineFromKbd<int>();
    std::cout << "\nIndiquez la verticale : ";
    y = nvs::lineFromKbd<int>();
    std::cout << "\nHorizontale ou Verticale (H/V) : ";
    std::cin>>in;
    if(in[0]=='h' || in[0]=='H'){
        hORv = false;
        getGame()->placeWall(hORv,x,y,playerNb);
    }else if(in[0]=='v' || in[0]=='V'){
        hORv = true;
        getGame()->placeWall(hORv,x,y,playerNb);
    }else{
        throw std::invalid_argument("Not horizontal or vertical input");
    }
}

void ConsoleQuoridor::move(int playerNb)
{
    Square* pos = getGame()->getplayers().at(playerNb)->getPos();
    std::vector<std::tuple<int,int>> moves = getGame()->checkMoves(playerNb);
    int x = ((pos->getX())/2)+1;
    int y = ((pos->getY())/2)+1;
    std::string out[] = {{"....."},{"....."},{"..P.."},{"....."},{"....."}};
    int move = 0;
    for (auto m : moves){
        out[((((std::get<0>(m))/2)+1)-x)+2][((((std::get<1>(m))/2)+1)-y)+2] = std::to_string(move)[0];
        move++;
    }
    for(auto str : out)
        std::cout<<str<<std::endl;
    std::cout<<"Pick move : ";
    int choice = nvs::lineFromKbd<int>();
    if(choice<0 || choice>=moves.size())
        throw std::invalid_argument("Picked unavailable move, please choose from shown numbers");
    getGame()->move(playerNb,std::get<0>(moves.at(choice)),std::get<1>(moves.at(choice)));
}

void ConsoleQuoridor::play()
{
    int player = 0;
    int numberOfPlayers = getGame()->getplayers().size();
    std::cout<<getGame()->getplayers().at(0)->getNumberOfWalls()<<std::endl;
    bool endOfGame = false;
    while(!endOfGame){
        bool hasPlayed = false;
        while(hasPlayed == false){
            try{
                choice(player);
                hasPlayed = true;
            }catch(std::invalid_argument & i){
                std::cout<<i.what()<<std::endl;
            }catch(std::exception & e){
                std::cout<<"Not a number"<<std::endl;
            }
        }
        endOfGame = getGame()->hasWon(player);
        if (!endOfGame)
            player = (player+1)%numberOfPlayers;
    }
    std::cout<<"Player "<<player+1<<" has won !"<<std::endl;
}

void ConsoleQuoridor::choice(int playerNb)
{
    std::cout<<"---- Player "<<playerNb+1<<" -----"<<std::endl;
    std::cout<<"1. Move\n2. Place Wall\n->";
    std::string in;
    std::cin>>in;
    switch(in[0]){
        case '1':
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            move(playerNb);
            break;
        case '2':
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            placeWall(playerNb);
            break;
       default:
            throw std::invalid_argument("Incorrect choice");
    }
}
