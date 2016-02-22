#ifndef WALL_H
#define WALL_H

#include "square.h"
#include <string>


class Wall : public Square{
public:
    Wall(int posX, int posY);
    std::string getString(){return "###";}

protected:
    bool isBuild_;

};

#endif // WALL_H
