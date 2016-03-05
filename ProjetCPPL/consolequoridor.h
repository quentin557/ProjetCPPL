#ifndef CONSOLEQUORIDOR_H
#define CONSOLEQUORIDOR_H

#include "quoridor.h"
#include <stdexcept>
#include "obersverpattern.h"


class ConsoleQuoridor : public Observer
{
public:
    ConsoleQuoridor(Quoridor *game);
    virtual void update();
    void placeWall(int playerNb);
    void move(int playerNb);
    void play();
    void choice(int playerNb);
    Quoridor* getGame(){return (Quoridor*)model;}
};

#endif // CONSOLEQUORIDOR_H
