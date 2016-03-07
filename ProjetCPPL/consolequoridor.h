/*!
 * \file consolequoridor.hpp
 *
 * \brief contains the temrinal interface of the game.
 *
 * \author 39766 & 42586
 */

#ifndef CONSOLEQUORIDOR_H
#define CONSOLEQUORIDOR_H

#include "quoridor.h"
#include <stdexcept>
#include "obersverpattern.h"


class ConsoleQuoridor : public Observer
{
public:
    /*!
     * \brief creates a new terminal interface for a given quoridor game.
     *
     * \param game pointer to subject watched.
     *
     */
    ConsoleQuoridor(Quoridor *game);
    /*!
     * \brief prints the board in terminal.
     */
    virtual void update();
    /*!
     * \brief asks player playerNb where he wishes to place a wall.
     *
     * \param playerNb index of player to place a wall.
     *
     * \exception std::invalid_argument if player does not ask for horizontal or vertical
     * placing of the wall. nvs::bad_string_convert if player does not type number when asked for
     * position.
     */
    void placeWall(int playerNb);
    /*!
     * \brief asks player playerNb where he wishes to move.
     *
     * \param playerNb index of player to move.
     *
     * \exception nvs::bad_string_convert if cannot convert input to int
     * std::invalid_argument if the player chooses non available move.
     */
    void move(int playerNb);
    /*!
     * \brief starts the game.
     */
    void play();
    /*!
     * \brief for player playerNb, asks what choice he wished to make in his turn.
     *
     * \param playerNb index of player's turn.
     *
     * \exception std::invalid_argument players chooses incorrectly in menu.
     */
    void choice(int playerNb);
    /*!
     * \brief return a pointer to the game.
     *
     * \return pointer to the subject (the quoridor).
     */
    Quoridor* getGame(){return (Quoridor*)model;}
};

#endif // CONSOLEQUORIDOR_H
