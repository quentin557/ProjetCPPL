#ifndef SQUARE_H
#define SQUARE_H

#include <string>

class Square
{
public:
    Square(int posX, int posY);
    virtual ~Square(){}
    inline int getX(){return posX_;}
    inline int getY(){return posY_;}

protected:
    int posX_;
    int posY_;
};

#endif // SQUARE_H
