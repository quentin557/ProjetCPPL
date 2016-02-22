#ifndef PLAYABLESQUARE_H
#define PLAYABLESQUARE_H

#include "player.h"
#include "square.h"

class PlayableSquare : public Square
{
public:
    PlayableSquare(int posX, int posY);
    char getChar(){return 'p';}
    void setPlayer(Player* player);

protected:
    Player * hasPlayer_;
};

#endif // PLAYABLESQUARE_H
