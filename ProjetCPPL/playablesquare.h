/*!
 * \file playablesquare.hpp
 *
 * \brief contains a PlayableSquare.
 *
 * \author 39766 & 42586
 */

#ifndef PLAYABLESQUARE_H
#define PLAYABLESQUARE_H

#include "player.h"
#include "square.h"
#include <iostream>

class PlayableSquare : public Square
{
public:
    /*!
     * \brief creates a new PlayableSquare with its position.
     *
     * \param posX the first coordinate of the square.
     * \param posY.the second coordinate of the square.
     */
    PlayableSquare(int posX, int posY);
    /*!
     * \brief returns pointer to player on the playable square
     * or nullptr if no player on the square.
     *
     * \return pointer to player on square (or nullptr if no player present).
     */
    Player* getPlayer() const{return hasPlayer_;}
    /*!
     * \brief sets a player on the square.
     *
     * \param player the player to place on the square.
     *
     */
    void setPlayer(Player* player);
    /*!
     * \brief sets the square free of its player.
     */
    void setFree();

protected:
    Player * hasPlayer_;
};

#endif // PLAYABLESQUARE_H
