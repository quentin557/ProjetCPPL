#include "playablesquare.h"

PlayableSquare::PlayableSquare(int posX, int posY) : Square(posX, posY), hasPlayer_{nullptr}
{

}

void PlayableSquare::setPlayer(Player *player)
{
    hasPlayer_ = player;
}

void PlayableSquare::setFree()
{
    hasPlayer_ = nullptr;
}

