#ifndef QUORIDOR_H
#define QUORIDOR_H

#include "board.h"
#include "player.h"
#include <vector>
#include <tuple>
#include <stdexcept>
#include "obersverpattern.h"

class Quoridor : public Subject{
public:
    Quoridor(int size, int numberOfPlayers = 2);
    ~Quoridor();

    void move(int playerNb, int x, int y);
    void placeWall(bool hORv, int y, int x);

    std::vector<std::tuple<int,int>> checkMoves(int playerNb);
    void initBacktrack();
    bool canStillWin(int playerNb);

    std::string to_string();
    std::vector<Player*> getplayers(){return players;}
    int getSize(){return board_.getSize();}
    std::vector<std::tuple<int,int>> getDestinations(int playerNb);

    void test(int x, int y);

protected:
    std::vector<std::tuple<int,int>> checkMoves(int x, int y, bool backtrack = false);
    void backtrack(int x, int y, std::vector<std::tuple<int,int>> destinations);
    std::vector<Player*> players;
    Board board_;
};

#endif // QUORIDOR_H
