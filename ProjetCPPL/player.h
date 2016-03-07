#ifndef PLAYER_H
#define PLAYER_H

#include "square.h"

class Player {
public:
    /*!
     * \brief construct a player.
     * \param numberOfWalls The "stock" of walls that the player can place.
     * \param start The starting position on the board following if the player is 1st, 2nd 3rd or 4th.
     * \param nb The number of the player, his name.
     */
    Player(int numberOfWalls, Square* start, std::string nb);
    /*!
     * \brief Returns the starting square of the player.
     * \return pointer to the player's starting square.
     */
    inline const Square* getStart() const{return start_;}
    /*!
     * \brief Returns the actual position of the player.
     * \return The position.
     */
    inline Square* getPos() const{return pos_;}
    /*!
     * \brief Returns the player's name.
     * \return The name.
     */
    inline std::string getPlayerNb() const{return playerNb_;}
    /*!
     * \brief Returns the number of remaining walls.
     * \return The number of walls.
     */
    inline int getNumberOfWalls() const{return numberOfWalls_;}
    /*!
     * \brief Move the player to a given position.
     * \param square pointer to squared moved towards.
     */
    void move(Square* square);
    /*!
     * \brief Decrement the number of walls remaining of the player by one.
     * meaning the player juste placed a wall.
     */
    void hasPlacedWall();


protected:
    int numberOfWalls_;
    const Square * start_;
    Square* pos_;
    const std::string playerNb_;
};

#endif // PLAYER_H
