#include "board.h"
#include <iostream>
#include <string>

Board::Board(int size) {
    int realSize = (size * 2) - 1;
    for (int i = 0; i < realSize; i++) {
        board_.push_back(std::vector<Square *>());
        for ( int j = 0; j < realSize; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                board_[i].push_back(new PlayableSquare(i, j));
            }
            else {
                board_[i].push_back(new Wall(i, j));
            }
        }
    }
}

std::string Board::to_string() {
    std::string value = "   ";
    Wall * temp;
    bool wallH = false;
    bool wallV = false;
    int cptH = 1;
    int cptV = 1;
    for (size_t i = 0; i < board_.size(); i++) {
        if (wallV) {
            value += "_ ";
            value += std::to_string(cptH++);
            value += " _";
            wallV = !wallV;
        }
        else {
            value += "_____";
            wallV = !wallV;
        }
    }
    value += "\n  |";
    for (size_t i = 0; i < board_.size(); i++) {
        for (size_t j = 0; j < board_.size(); j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                value += "     "; //square
            }
            else {
                temp = (Wall *)getSquareAt(i, j);
                if (temp->getBuild()) {
                    value += "#####";

                }
                else {
                    value += "     "; //No wall
                }
            }
        }
        if (wallH) {
            value += "|\n";
            value += std::to_string(cptV++);
            value += "-|";
            wallH = !wallH;

        }
        else {
            value += "|\n  |";
            wallH = !wallH;
        }
        for (size_t j = 0; j < board_.size(); j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                PlayableSquare * play = dynamic_cast<PlayableSquare *>(getSquareAt(i,j));
                if (play->getPlayer()) {
                    value+="  ";
                    value+=play->getPlayer()->getPlayerNb();
                    value+="  ";
                }
                else {
                    value += "  .  "; //square
                }
            }
            else {
                temp = (Wall *)getSquareAt(i, j);
                if (temp->getBuild()) {
                    value += "#####";

                }
                else {
                    value += "     "; //No wall
                }
            }
        }

        value += "|\n  |";
        for (size_t j = 0; j < board_.size(); j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                value += "     "; //square
            }
            else {
                temp = (Wall *)getSquareAt(i, j);
                if (temp->getBuild()) {
                    value += "#####";

                }
                else {
                    value += "     "; //No wall
                }
            }
        }
        value += "|\n  |";
    }
    for (size_t i = 0; i < board_.size(); i++) {
        value += "-----";
    }
    value += "|\n";
    return value;
}

void Board::setPlayerAt(Player  *player, int x, int y) {
    if (x % 2 == 0 && y % 2 == 0) {
        PlayableSquare * square = dynamic_cast<PlayableSquare *> (board_[x][y]);
        square->setPlayer(player);
    }
    else {
        throw std::invalid_argument("Board::setPlayerAt : pos not playable square");
    }
}

Square * Board::getSquareAt(int x, int y) {
    return board_[x][y];
}

void Board::move(Player * p, int x, int y) {
    if (x % 2 == 0 && y % 2 == 0) {
        PlayableSquare * square = dynamic_cast<PlayableSquare *>
                                  (board_[p->getPos()->getX()][p->getPos()->getY()]);
        square -> setFree();
        setPlayerAt(p, x, y);
    }
    else {
        throw std::invalid_argument("Board::move : pos not playable square");
    }
}

Board::~Board() {
    int realSize = board_.size();
    for (int i = 0; i < realSize; i++) {
        for ( int j = 0; j < realSize; j++) {
            delete(board_[i][j]);
        }
    }
}

void Board::placeWall(bool hORv, int x, int y) {
    Wall * temp;
    for (int i = -1; i < 2; i++) {
        if (hORv) {
            temp = dynamic_cast<Wall*>(board_[x + i][y]);
            temp->build();
        }else{
            temp = dynamic_cast<Wall*>(board_[x][y + i]);
            temp->build();
        }
    }
}

void Board::clearWall(bool hORv, int x, int y)
{
    Wall * temp;
    for (int i = -1; i < 2; i++) {
        if (hORv) {
            temp = dynamic_cast<Wall*>(board_[x + i][y]);
            temp->demolish();
        }else{
            temp = dynamic_cast<Wall*>(board_[x][y + i]);
            temp->demolish();
        }
    }
}

bool Board::isInside(size_t x, size_t y) {
    return (x >= 0 && x < board_.size() && y >= 0 && y < board_.size());
}
