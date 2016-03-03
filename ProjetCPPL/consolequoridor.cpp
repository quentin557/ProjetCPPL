#include "consolequoridor.h"

ConsoleQuoridor::ConsoleQuoridor(int size,
                                 int numberOfPlayers) : Observer(new Quoridor(size,numberOfPlayers)) {

}

void ConsoleQuoridor::update()
{
    std::cout<<getGame()->to_string()<<std::endl;
}

void ConsoleQuoridor::placeWall() {

    int x, y, size;
    bool hORv;
    size = getGame()->getSize();
    std::cout << "Indiquez l'horizontale :";
    y = getInt(size);
    std::cout << std::endl;
    std::cout << "Indiquez la verticale :";
    x = getInt(size);
    std::cout << std::endl;
    std::cout << "Horizontale ou Verticale? H/V";
    hORv = pivot();

    try {
        getGame()->placeWall(hORv, y, x);
    }
    catch (std::invalid_argument e) {
        std::cout << "Un mur est déjà placé sur les coordonées données."
                  << std::endl;
        placeWall();
    }
}

bool ConsoleQuoridor::pivot() {
    std::cin.ignore();
    std::string piv;
    std::cin >> piv;
    while (piv.compare("V") != 0 && piv.compare("v") != 0 &&
            piv.compare("H") != 0 && piv.compare("h") != 0) {
        std::cout << "Valeurs possibles :H h V v";
        std::cin >> piv;
    }
    if (piv.compare("H") == 0 || piv.compare("h") == 0) {
        return false;
    }
    else return true;
}

int ConsoleQuoridor::getInt(int size) {
    int nbr;
    size = (size / 2) + 1;
    std::cin >> nbr;
    while (nbr < 0 || nbr > size - 1) {
        std::cout << "Un entier de 1 a " << size - 1 << " S.V.P ! " <<
                  std::endl;
        std::cin.clear();
        std::string ignore;
        std::getline(std::cin, ignore);
        std::cin >> nbr;
    }
    return nbr;
}


void ConsoleQuoridor::test()
{
    getGame()->move(0,2,0);
    placeWall();
    placeWall();
    placeWall();
    placeWall();
    std::cout<<getGame()->canStillWin(0)<<std::endl;
}
