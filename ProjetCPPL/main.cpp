#include <iostream>

using namespace std;
#include "board.h"
#include "quoridor.h"

int main()
{
    int size = 5;
    Quoridor o = Quoridor(size,4);
    o.move(0,2,0);
    std::cout<<o.to_string()<<std::endl;
    o.test(0,0);
    std::cout<<o.to_string()<<std::endl;
    std::vector<std::tuple<int,int>> moves = o.checkMoves(0);
    for(auto m : moves){
        std::cout<<"possible move at "<<std::get<0>(m)<<" , "<<std::get<1>(m)<<std::endl;
    }

    return 0;
}
