#ifndef CONSOLEQUORIDOR_H
#define CONSOLEQUORIDOR_H

#include "quoridor.h"
#include <stdexcept>
#include "obersverpattern.h"


class ConsoleQuoridor : public Observer
{
public:
    ConsoleQuoridor(int size, int numberOfPlayers = 2);
    virtual void update();
    void placeWall();
    int getInt(int size);
    bool pivot();
    void test();
    Quoridor* getGame(){return (Quoridor*)model;}
};

#endif // CONSOLEQUORIDOR_H
