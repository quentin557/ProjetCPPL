#ifndef BOARD_H
#define BOARD_H

#include "playablesquare.h"
#include "wall.h"
#include <vector>
#include <stdexcept>

class Board
{
public:
    Board(int size);
    ~Board();
    std::string to_string();
    void setPlayerAt(Player *player, int x, int y);
    Square* getSquareAt(int x, int y);
    void move(Player* p, int x, int y);
    int getInt();
    bool isInside(size_t x, size_t y);
    void placeWall(bool hORv, int y,int x);
    inline int getSize(){return board_.size();}


protected:
    std::vector<std::vector<Square*>> board_;
};

#endif // BOARD_H
