/*!
 * \file board.hpp
 *
 * \brief contains the board of the game.
 *
 * \author 39766 & 42586
 */

#ifndef BOARD_H
#define BOARD_H

#include "playablesquare.h"
#include "wall.h"
#include <vector>
#include <stdexcept>

class Board
{
public:

    /*!
     * \brief Creates a new board of size size. It is a matrix of Squares pointers
     * that point to either a Wall Square or a playable square.
     *
     * \param size the size of the matrix to be created.
     *
     */
    Board(int size);
    /*!
     * \brief destroyes the board. So deletes all the pointers created.
     */
    ~Board();
    /*!
     * \brief converts matrix to printable string.
     */
    std::string to_string();
    /*!
     * \brief takes a pointer to a player and puts it at given coordinates.
     *
     * \param player pointer to the player to put at given position.
     *
     * \param x first coordinate of matrix.
     * \param y second coordinate of matrix.
     *
     * \exception std::invalid_argument if position given is not a playable Square.
     */
    void setPlayerAt(Player *player, int x, int y);
    /*!
     * \brief asks the board to give the pointer to the
     * square on given coordinates. no check made on those coordinates.
     *
     * \param x first coordinate of matrix.
     * \param y second coordinate of matrix.
     *
     * \return pointer to square at given coordinates.
     * \exception vector exception if out of bound.
     */
    Square* getSquareAt(int x, int y);
    /*!
     * \brief moves a player p given to the coordinates x,y given.
     * checks other than playable square have to be made previously.
     *
     * \param p pointer to player to move.
     * \param x first coordinate of matrix.
     * \param y second coordinate of matrix.
     *
     * \exception std:invalid_argument if position is not a playable square.
     */
    void move(Player* p, int x, int y);
    /*!
     * \brief checks if the given position (x,y) is still inside the
     * limits of the board.
     *
     * \param x first coordinate of matrix.
     * \param y second coordinate of matrix.
     *
     * \return boolean that indicates wether the position is inside the board or not.
     */
    bool isInside(size_t x, size_t y);
    /*!
     * \brief builds a wall at given position and 2 adjacent squares
     * depending on hORv (North and sout or East and west of position).
     *
     * \param hORv indicates wether walls has to be build verticaly or horizontaly.
     * \param x first coordinate of matrix.
     * \param y second coordinate of matrix.
     *
     * \exception dynamic_cast error if given position is not a wall square.
     */
    void placeWall(bool hORv, int x, int y);
    /*!
     * \brief destroys a wall at given position and 2 adjacent squares
     * depending on hORv (North and sout or East and west of position).
     *
     * \param hORv indicates wether wall to be cleared is vertical or horizontal.
     * \param x first coordinate of matrix.
     * \param y second coordinate of matrix.
     *
     * \exception dynamic_cast error if given position is not a wall square.
     */
    void clearWall(bool hORv, int x, int y);
    /*!
     * \brief return the size of the board.
     *
     * \return size of board.
     */
    inline int getSize(){return board_.size();}


protected:
    std::vector<std::vector<Square*>> board_;
};

#endif // BOARD_H
