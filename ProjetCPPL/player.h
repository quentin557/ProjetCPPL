#ifndef PLAYER_H
#define PLAYER_H

#include "square.h"

class Player {
public:
    Player(int numberOfWalls, Square* start, std::string nb);
    inline const Square* getStart() const{return start_;}
    inline Square* getPos() const{return pos_;}
    inline std::string getPlayerNb() const{return playerNb_;}
    inline int getNumberOfWalls() const{return numberOfWalls_;}
    void move(Square* square);
    void hasPlacedWall();


protected:
    int numberOfWalls_;
    const Square * start_;
    Square* pos_;
    const std::string playerNb_;
};

#endif // PLAYER_H
