#ifndef WALL_H
#define WALL_H

#include "square.h"
#include <string>


class Wall : public Square{
public:
    Wall(int posX, int posY);
    std::string getString(){return "###";}
    void build(){this->isBuild_ = true;}
    inline bool getBuild(){return isBuild_;}

protected:
    bool isBuild_;

};

#endif // WALL_H
