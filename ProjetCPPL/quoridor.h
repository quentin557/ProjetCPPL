#ifndef QUORIDOR_H
#define QUORIDOR_H

#include "board.h"
#include "player.h"
#include <vector>
#include <tuple>
#include <stdexcept>

class Quoridor {
public:
    Quoridor(int size, int numberOfPlayers = 2);
    void move(Player p, Square* square);
    //std::vector<std::tuple>> checkMoves(player p);
    void test();

protected:
    std::vector<Player> players;
    Board board_;
};

#endif // QUORIDOR_H
