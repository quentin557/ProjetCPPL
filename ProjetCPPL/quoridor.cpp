#include "quoridor.h"
#include <iostream>
#include <algorithm>

Quoridor::Quoridor(int size, int numberOfPlayers) : board_{Board(size)}
{
    if(size>19 || size<5 || size%2==0){
        throw std::invalid_argument("Quoridor::Quoridor : Invalid Size");
    }
    if (numberOfPlayers !=2 && numberOfPlayers!=4){
        throw std::invalid_argument("Quoridor::Quoridor : Invalid NumberOfPlayers");
    }
    int numberOfWalls = 0;
    if(numberOfPlayers==2){
        numberOfWalls = size+1;
        Square* start = board_.getSquareAt(0,size-1);
        Player* p1 = new Player(numberOfWalls,start,"1"); //North
        board_.setPlayerAt(p1,0,size-1);
        start = board_.getSquareAt((size*2)-2,size-1);
        Player* p2 = new Player(numberOfWalls,start,"2"); //South
        board_.setPlayerAt(p2,(size*2)-2,size-1);
        players.push_back(p1);
        players.push_back(p2);
    }else{
        numberOfWalls = (size + 1)/2;
        Square* start = board_.getSquareAt(0,size-1);
        Player* p1 = new Player(numberOfWalls,start,"1"); //North
        board_.setPlayerAt(p1,0,size-1);
        start = board_.getSquareAt((size*2)-2,size-1);
        Player* p2 = new Player(numberOfWalls,start,"2"); //South
        board_.setPlayerAt(p2,(size*2)-2,size-1);
        start = board_.getSquareAt(size-1,(size*2)-2);
        Player* p3 = new Player(numberOfWalls,start,"3"); //East
        board_.setPlayerAt(p3,size-1,(size*2)-2);
        start = board_.getSquareAt(size-1,0);
        Player* p4 = new Player(numberOfWalls,start,"4"); //West
        board_.setPlayerAt(p4,size-1,0);
        players.push_back(p1);
        players.push_back(p2);
        players.push_back(p3);
        players.push_back(p4);
    }
}

Quoridor::~Quoridor()
{
    for (size_t i =0; i< players.size();i++){
        delete (players[i]);
    }
    players.clear();
}

void Quoridor::move(int playerNb, int x, int y)
{
    board_.move(players.at(playerNb),x,y);
    players.at(playerNb)->move(board_.getSquareAt(x,y));
    notify();
}

void Quoridor::placeWall(bool hORv, int y, int x)
{
    board_.placeWall(hORv,y,x);
    notify();
}

std::vector<std::tuple<int,int>> Quoridor::checkMoves(int playerNb){
    Player *p = players.at(playerNb);
    Square* pos = p->getPos();
    return checkMoves(pos->getX(),pos->getY());
}

void Quoridor::initBacktrack()
{
    for(int i = 0; i<board_.getSize();i++){
        for (int j =0; j<board_.getSize();j++){
            board_.getSquareAt(i,j)->setVisited(false);
        }
    }
}

bool Quoridor::canStillWin(int playerNb)
{
    bool res = false;
    Player *p = players.at(playerNb);
    initBacktrack();
    backtrack(p->getPos()->getX(),p->getPos()->getY(),getDestinations(playerNb));
    for(auto m : getDestinations(playerNb)){
        if(board_.getSquareAt(std::get<0>(m),std::get<1>(m))->getVisited()==true){
            res = true;
        }
    }
    return res;
}

std::vector<std::tuple<int,int>> Quoridor::checkMoves(int x, int y, bool backtrack)
{
    Square* pos = board_.getSquareAt(x,y);
    std::vector<std::tuple<int,int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
    std::vector<std::tuple<int,int>> moves;
    for(std::tuple<int,int> dir : directions){
        int newX = pos->getX()+std::get<0>(dir);
        int newY = pos->getY()+std::get<1>(dir);
        if(board_.isInside(newX,newY)){
            Wall* test = dynamic_cast<Wall*>(board_.getSquareAt(newX,newY));
            if(test!=0 && !test->getBuild()){
                newX+=std::get<0>(dir);
                newY+=std::get<1>(dir);
                PlayableSquare* destination = dynamic_cast<PlayableSquare*>(board_.getSquareAt(newX,newY));
                if(destination->getPlayer()==nullptr || backtrack == true){
                    std::tuple<int,int> possibleMove= {newX,newY};
                    moves.push_back(possibleMove);
                }else if(not backtrack){ //only if checking player move, not while backtracking
                    //pawn on square
                    //Jump
                    int jumpX = newX;
                    int jumpY = newY;
                    jumpX+=std::get<0>(dir);
                    jumpY+=std::get<1>(dir);
                    test = dynamic_cast<Wall*>(board_.getSquareAt(jumpX,jumpY));
                    jumpX+=std::get<0>(dir);
                    jumpY+=std::get<1>(dir);
                    destination = dynamic_cast<PlayableSquare*>(board_.getSquareAt(jumpX,jumpY));
                    if(test!=0 && !test->getBuild() && destination->getPlayer()==nullptr){
                        std::tuple<int,int> possibleMove= {jumpX,jumpY};
                        moves.push_back(possibleMove);
                    }else{
                    //Diagonals
                        if(std::get<0>(dir)==0){
                            newX+=1;
                            std::tuple<int,int> possibleMove= {newX,newY};
                            if(board_.isInside(newX,newY)){moves.push_back(possibleMove);}
                            newX-=2;
                            possibleMove= {newX,newY};
                            if(board_.isInside(newX,newY)){moves.push_back(possibleMove);}
                        }else if(std::get<1>(dir)==0){
                            newY+=1;
                            std::tuple<int,int> possibleMove= {newX,newY};
                            if(board_.isInside(newX,newY)){moves.push_back(possibleMove);}
                            newY-=2;
                            possibleMove= {newX,newY};
                            if(board_.isInside(newX,newY)){moves.push_back(possibleMove);}
                        }
                    }
                }
            }
        }
    }
    return moves;
}

void Quoridor::backtrack(int x, int y, std::vector<std::tuple<int, int> > destinations)
{
    board_.getSquareAt(x,y)->setVisited(true);
    std::vector<std::tuple<int, int>> moves = checkMoves(x,y,true);
    for (auto move : moves){
        if(board_.getSquareAt(std::get<0>(move),std::get<1>(move))->getVisited()==false){
            backtrack(std::get<0>(move),std::get<1>(move),destinations);
        }
    }
}


std::string Quoridor::to_string()
{
    return board_.to_string();
}

std::vector<std::tuple<int, int> > Quoridor::getDestinations(int playerNb)
{
    Player *p = players.at(playerNb);
    const Square* pos = p->getStart();
    std::vector<std::tuple<int, int> > dest;
    int size = board_.getSize();
    if(pos->getX()==0){ //Player North
        for(int i = 0; i<size;i++)
            if(i%2==0) dest.push_back({size-1,i});
    }else if(pos->getY()==0){ //Player West
        for(int i = 0; i<size;i++)
            if(i%2==0) dest.push_back({i,size-1});
    }else if(pos->getX()==size-1){ //Player South
        for(int i = 0; i<size;i++)
            if(i%2==0) dest.push_back({0,i});
    }else if(pos->getY()==size-1){ //Player East
        for(int i = 0; i<size;i++)
            if(i%2==0) dest.push_back({i,0});
    }
    return dest;
}

void Quoridor::test(int x, int y)
{
    //board_.placeWall();
//    move(0,x,y);
//    for (auto p : players){
//        std::cout<<p.getNumberOfWalls()<<std::endl;
//    }
//    PlayableSquare* test = (PlayableSquare*)board_.getSquareAt(x,y);
//    if(test->getPlayer()==nullptr){
//        std::cout<<"no player"<<std::endl;
//    }else{
//        std::cout<<"player found"<<std::endl;
//    }
//    std::vector<std::tuple<int,int>> moves = checkMoves(0);
//    for(auto m : moves){
//        std::cout<<"possible move at "<<std::get<0>(m)<<" , "<<std::get<1>(m)<<std::endl;
//    }
}
