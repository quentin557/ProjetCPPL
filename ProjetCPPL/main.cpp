#include <iostream>
#include <string>
#include "keyboard.hpp"

using namespace std;
#include "board.h"
#include "consolequoridor.h"

void makeQuoridor(){
    int size, Nb {-1};
    try{
        cout<<"----- Quoridor -----"<<endl;
        cout<<"Choose size : ";
        size = nvs::lineFromKbd<int>();
        cout<<"Choose Number Of Players (2 or 4) : ";
        Nb = nvs::lineFromKbd<int>();
        Quoridor* game = new Quoridor(size,Nb);
        ConsoleQuoridor view = ConsoleQuoridor(game);
        view.play();
        delete game;
    }catch(std::invalid_argument e){
        cout<<e.what()<<endl;
    }catch( exception & e){
        cout<<"Not a Number"<<endl;
    }
}

void menu(){
    bool exit = false;
    std::string in;
    while(!exit){
        cout<<"----- Menu -----"<<endl;
        cout<<"1. Play Game"<<endl;
        cout<<"2. Exit"<<endl;
        cout<<"----------------"<<endl;
        cout<<"-> ";
        cin>>in;
        cout<<endl;
        if(in=="1"){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            makeQuoridor();
        }else if(in=="2"){
            exit = true;
        }
    }
}

int main()
{
    menu();
    return 0;
}
