#include <iostream>

using namespace std;
#include "board.h"
#include "consolequoridor.h"

int main()
{
//    int size = 5;
//    Quoridor o = Quoridor(size,4);
//    o.move(0,2,0);
//    std::cout<<o.to_string()<<std::endl;
//    o.test(0,0);
//    std::cout<<o.to_string()<<std::endl;
//    std::vector<std::tuple<int,int>> moves = o.checkMoves(0);
//    for(auto m : moves){
//        std::cout<<"possible move at "<<std::get<0>(m)<<" , "<<std::get<1>(m)<<std::endl;
//    }
    ConsoleQuoridor test = ConsoleQuoridor(5,4);
    //while(true)
    test.test();
//    std::vector<int> test = {2,3};
//    std::vector<int> test2 = {4,5};
//    test.insert(test.end(), test2.begin(), test2.end());
//    for (auto m : test)
//        cout<<m<<" ";

    return 0;
}
