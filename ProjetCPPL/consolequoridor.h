#ifndef CONSOLEQUORIDOR_H
#define CONSOLEQUORIDOR_H

#include "quoridor.h"
#include <stdexcept>



class ConsoleQuoridor
{
public:
    ConsoleQuoridor(int size, int numberOfPlayers = 2);

protected:
    Quoridor game_;
};

#endif // CONSOLEQUORIDOR_H
