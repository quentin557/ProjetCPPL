#include <iostream>

using namespace std;
#include "board.h"
#include "quoridor.h"

int main()
{
    int size = 9;
    Board test = Board(size);
    test.print();
    test.placeWall();
    test.print();
    test.placeWall();
    test.print();
    int y;
    cout<<"Entier : ";
    cin>>y;
    cout<<y<<endl;

    Quoridor o = Quoridor(size);
    return 0;
}
