/*!
 * \file wall.hpp
 *
 * \brief contains a wall square.
 *
 * \author 39766 & 42586
 */


#ifndef WALL_H
#define WALL_H

#include "square.h"

class Wall : public Square{
public:
    /*!
     * \brief creates a new Wall square with its position.
     *
     * \param posX the first coordinate of the square.
     * \param posY.the second coordinate of the square.
     */
    Wall(int posX, int posY);
    /*!
     * \brief indicates to wall square to build a wall on itself.
     */
    void build(){this->isBuild_ = true;}
    /*!
     * \brief indicates to wall square to demolish the wall on itself.
     */
    void demolish(){this->isBuild_ = false;}
    /*!
     * \brief lets us know if the wall has been built on this square.
     * \return true if a wall has been build, false otherwise.
     */
    inline bool getBuild(){return isBuild_;}

protected:
    bool isBuild_;

};

#endif // WALL_H
