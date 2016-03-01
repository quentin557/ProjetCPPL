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
    ~Quoridor();
    void move(int playerNb, int x, int y);
    std::vector<std::tuple<int,int>> checkMoves(int playerNb, bool backtrack = false);
    std::vector<std::tuple<int,int>> backtrack(int playerNb);
    std::string to_string();
    std::vector<Player*> getplayers(){return players;}

    void test(int x, int y);

protected:
    std::vector<Player*> players;
    Board board_;
};

#endif // QUORIDOR_H
