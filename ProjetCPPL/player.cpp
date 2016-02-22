#include "player.h"

Player::Player(int numberOfWalls, Square *start, std::string nb) : numberOfWalls_{numberOfWalls}, start_{start},pos_{start},playerNb_{nb}
{
}

void Player::move(Square * square)
{
    pos_ = square;
}

