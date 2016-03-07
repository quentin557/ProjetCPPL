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
    /*!
     * \brief Construct a quoridor game.
     * \param size The size of the board of the game.
     * \param numberOfPlayers The number of players (2 or 4).
     * \exception std::invalid_argument if the board's size or the number of players are incorrect.
     */
    Quoridor(int size, int numberOfPlayers = 2);
    ~Quoridor();
    /*!
     * \brief Allow a player to move on the board.
     * \param playerNb The name of the player.
     * \param x The x position.
     * \param y The y position.
     * \exception std::invalid_argument if the player wants to move to an unavailable position.
     */
    void move(int playerNb, int x, int y);
    /*!
     * \brief Allow a player to place a wall
     * \param hORv If the wall is horizontal(true) or vertical(false).
     * \param x The x position following hORv
     * \param y The y position following hORv
     * \param playerNb The name of the player.
     * \exception std::invalid_argument if the player has no wall anymore,
     *            if there's already a wall in the selected place or
     *            if an opponent can't win anymore because of this.
     */
    void placeWall(bool hORv, int x, int y, int playerNb);
    /*!
     * \brief Cancel a wall placement
     * \param hORv the pivot of the placed wall.
     * \param x The x position
     * \param y The y position
     */
    void clearWall(bool hORv, int x, int y);

    /*!
     * \brief Check the possible moves of the player.
     * \param The name of the player.
     * \return The possible moves.
     */
    std::vector<std::tuple<int,int>> checkMoves(int playerNb);
    /*!
     * \brief Initialise the backtracker.
     * makes all squares of the board unvisited.
     */
    void initBacktrack();
    /*!
     * \brief Return if the selected player can still win.
     * \param playerNb The name of the player.
     * \return If he can still win or not.
     */
    bool canStillWin(int playerNb);
    /*!
     * \brief Return if the selected player has won.
     * \param The name of the player.
     * \return If he won or not.
     */
    bool hasWon(int playerNb);
    /*!
     * \brief Show the game's board.
     * \return The game's board converted to string.
     */
    std::string to_string();
    /*!
     * \brief Returns a list of the players.
     * \return the list.
     */
    std::vector<Player*> getplayers(){return players;}
    /*!
     * \brief Returns the size of the board.
     * \return The size.
     */
    int getSize(){return board_.getSize();}
    /*!
     * \brief Returns the winning positions following the player.
     * \param playerNb The name of the player.
     * \return  The winning positions.
     */
    std::vector<std::tuple<int,int>> getDestinations(int playerNb);

protected:
    /*!
     * \brief Check the possible moves of a given position.
     * \param x The x position.
     * \param y The y position.
     * \param Only check the lateral positions if the backtrack is on.
     * \return The possibles moves.
     */
    std::vector<std::tuple<int,int>> checkMoves(int x, int y, bool backtrack = false);
    /*!
     * \brief Scan the whole board to show all possible ways to win if it's still possible.
     * \param x The position x to begin.
     * \param y The position y to begin.
     */
    void backtrack(int x, int y);
    std::vector<Player*> players;
    Board board_;
};

#endif // QUORIDOR_H
