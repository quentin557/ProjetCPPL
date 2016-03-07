/*!
 * \file Square.hpp
 *
 * \brief contains a square.
 *
 * \author 39766 & 42586
 */

#ifndef SQUARE_H
#define SQUARE_H

#include <string>

class Square
{
public:
    /*!
     * \brief creates a new square with its given position.
     * \param posX the first coordinate of the square.
     * \param posY the second coordinate of the square.
     */
    Square(int posX, int posY);
    /*!
     * \brief virtual destructor.
     */
    virtual ~Square(){}
    /*!
     * \brief returns the first coordinate of the square
     * \return the first coordinate of the square
     */
    inline int getX() const{return posX_;}
    /*!
     * \brief returns the second coordinate of the square
     * \return the second coordinate of the square
     */
    inline int getY() const{return posY_;}
    /*!
     * \brief indicates if square has been visited by backtrack or not
     * \return value of visited_.
     */
    inline bool getVisited() const{return visited_;}
    /*!
     * \brief changes the value of visited_.
     * \param newVisit the new value to be saved.
     */
    inline void setVisited(bool newVisit){visited_=newVisit;}

protected:
    const int posX_;
    const int posY_;
    bool visited_;
};

#endif // SQUARE_H
