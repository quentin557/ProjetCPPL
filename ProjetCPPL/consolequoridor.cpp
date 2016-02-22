#include "consolequoridor.h"

ConsoleQuoridor::ConsoleQuoridor(int size, int numberOfPlayers)
{
    if(size>19 || size<5){
        throw std::invalid_argument("ConsoleQuoridor::ConsoleQuoridor : Invalid Size");
    }
    if(numberOfPlayers==2){

    }else if(numberOfPlayers==4){

    }else{
        throw std::invalid_argument("ConsoleQuoridor::ConsoleQuoridor : Invalid NumberOfPlayers");
    }
}

