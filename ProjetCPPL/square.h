#ifndef SQUARE_H
#define SQUARE_H

#include <string>

class Square
{
public:
    Square(int posX, int posY);
    virtual ~Square(){}
    inline int getX() const{return posX_;}
    inline int getY() const{return posY_;}
    inline bool getVisited() const{return visited_;}
    inline void setVisited(bool newVisit){visited_=newVisit;}

protected:
    const int posX_;
    const int posY_;
    bool visited_;
};

#endif // SQUARE_H
