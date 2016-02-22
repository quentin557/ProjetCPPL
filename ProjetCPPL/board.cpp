#include "board.h"
#include <iostream>
#include <string>

Board::Board(int size)
{
    int realSize =(size*2)-1;
    for (int i = 0; i<realSize;i++){
        board_.push_back(std::vector<Square*>());
        for( int j = 0; j<realSize;j++){
            if(i%2==0 && j%2==0){
                board_[i].push_back(new PlayableSquare(i,j));
            }else{
                board_[i].push_back(new Wall(i,j));
            }
        }
    }
}

void Board::print(){
    std::string value="";

    std::cout<<board_.size()<<std::endl;
    for (size_t i = 0; i<board_.size();i++){
        for(size_t j = 0; j<board_.size();j++){
            if(i%2==0 && j%2==0){
                value +="     ";

            }else{
                value +="#####";
            }

        }
        value +="\n";
        for(size_t j = 0; j<board_.size();j++){
            if(i%2==0 && j%2==0){
                value +="  S  ";

            }else{
                value +="#####";
            }

        }
        value +="\n";
        for(size_t j = 0; j<board_.size();j++){
            if(i%2==0 && j%2==0){
                value +="     ";

            }else{
             value +="#####";
            }

           }
        value +="\n";
    }

    std::cout<<value;

}






/*
    for (size_t i = 0; i<board_.size();i++){

        for (size_t j = 0; j<board_.size();j++){
                if(i%2==0 && j%2==0){
                    value +="   ";
                    //board_[i].push_back(new PlayableSquare(i,j));
                }else{
                    value +="###";
                    //board_[i].push_back(new Wall(i,j));
                }


            //std::cout<<board_[i][j]->getString();

        }
        std::cout<<std::endl;
    }
    */


void Board::setPlayerAt(Player *player, int x, int y)
{
    if (x%2==0 && y%2==0){
        PlayableSquare* square = (PlayableSquare*)board_[x][y];
        square->setPlayer(player);
    }else{
        throw std::invalid_argument("Board::setPlayerAt : pos not playable square");
    }
}

Square *Board::getSquareAt(int x, int y)
{
    return board_[x][y];
}

void Board::move(Player *p, int x, int y)
{
    if (x%2==0 && y%2==0){
        PlayableSquare* square = (PlayableSquare*)board_[x][y];
        square -> setPlayer(nullptr);
        setPlayerAt(p,x,y);
    }else{
        throw std::invalid_argument("Board::move : pos not playable square");
    }
}

Board::~Board(){
    int realSize = board_.size();
    for (int i = 0; i<realSize;i++){
        for( int j = 0; j<realSize;j++){
            delete(board_[i][j]);
        }
    }
}

