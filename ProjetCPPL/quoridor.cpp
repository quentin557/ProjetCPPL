#include "quoridor.h"

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
        Player p1 = Player(numberOfWalls,start,"1"); //North
        Player* p= &p1;
        board_.setPlayerAt(p,0,size-1);
        start = board_.getSquareAt((size*2)-2,size-1);
        Player p2 = Player(numberOfWalls,start,"2"); //South
        p= &p2;
        board_.setPlayerAt(p,(size*2)-2,size-1);
        players.push_back(p1);
        players.push_back(p2);
    }else{
        numberOfWalls = (size + 1)/2;
        //Player p1 = Player(numberOfWalls); //North
        //Player p2 = Player(numberOfWalls); //South
        //Player p3 = Player(numberOfWalls); //East
        //Player p4 = Player(numberOfWalls); //West
    }
}

void Quoridor::move(Player p, Square *square)
{
    p.move(square);
}

void Quoridor::test(){
    board_.print();
}
