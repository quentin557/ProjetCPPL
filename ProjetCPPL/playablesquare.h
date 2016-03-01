#ifndef PLAYABLESQUARE_H
#define PLAYABLESQUARE_H

#include "player.h"
#include "square.h"
#include <iostream>

class PlayableSquare : public Square
{
public:
    PlayableSquare(int posX, int posY);
    Player* getPlayer() const{return hasPlayer_;}
    void setPlayer(Player* player);
    void setFree();

protected:
    Player * hasPlayer_;
};

#endif // PLAYABLESQUARE_H
