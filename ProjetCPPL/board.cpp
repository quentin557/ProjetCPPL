#include "board.h"
#include <iostream>
#include <string>

Board::Board(int size) {
    int realSize = (size * 2) - 1;
    for (int i = 0; i < realSize; i++) {
        board_.push_back(std::vector<Square *>());
        for ( int j = 0; j < realSize; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                board_[i].push_back(new PlayableSquare(i, j));
            }
            else {
                board_[i].push_back(new Wall(i, j));
            }
        }
    }
}

void Board::print() {
    std::string value = "   ";

    Wall * temp;
    bool wallH = false;
    bool wallV = false;
    int cptH = 1;
    int cptV = 1;

    for (size_t i = 0; i < board_.size(); i++) {
        if (wallV) {
            value += "_ ";
            value += std::to_string(cptH++);
            value += " _";
            wallV = !wallV;
        }
        else {
            value += "_____";
            wallV = !wallV;
        }

    }
    value += "\n  |";
    std::cout << board_.size() << std::endl;
    for (size_t i = 0; i < board_.size(); i++) {
        for (size_t j = 0; j < board_.size(); j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                value += "     "; //square
            }
            else {
                temp = (Wall *)getSquareAt(i, j);
                if (temp->getBuild()) {
                    value += "#####";

                }
                else {
                    value += "     "; //No wall
                }
            }
        }
        if (wallH) {
            value += "|\n";
            value += std::to_string(cptV++);
            value += "-|";
            wallH = !wallH;

        }
        else {
            value += "|\n  |";
            wallH = !wallH;
        }
        for (size_t j = 0; j < board_.size(); j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                value += "  S  "; //square
            }
            else {
                temp = (Wall *)getSquareAt(i, j);
                if (temp->getBuild()) {
                    value += "#####";

                }
                else {
                    value += "     "; //No wall
                }
            }
        }

        value += "|\n  |";
        for (size_t j = 0; j < board_.size(); j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                value += "     "; //square
            }
            else {
                temp = (Wall *)getSquareAt(i, j);
                if (temp->getBuild()) {
                    value += "#####";

                }
                else {
                    value += "     "; //No wall
                }
            }
        }
        value += "|\n  |";
    }
    for (size_t i = 0; i < board_.size(); i++) {
        value += "-----";
    }
    value += "|\n";
    std::cout << value;

}

void Board::setPlayerAt(Player * player, int x, int y) {
    if (x % 2 == 0 && y % 2 == 0) {
        PlayableSquare * square = (PlayableSquare *)board_[x][y];
        square->setPlayer(player);
    }
    else {
        throw std::invalid_argument("Board::setPlayerAt : pos not playable square");
    }
}

Square * Board::getSquareAt(int x, int y) {
    return board_[x][y];
}

void Board::move(Player * p, int x, int y) {
    if (x % 2 == 0 && y % 2 == 0) {
        PlayableSquare * square = (PlayableSquare *)
                                  board_[p->getPos()->getX()][p->getPos()->getY()];
        square -> setPlayer(nullptr);
        setPlayerAt(p, x, y);
    }
    else {
        throw std::invalid_argument("Board::move : pos not playable square");
    }
}

Board::~Board() {
    int realSize = board_.size();
    for (int i = 0; i < realSize; i++) {
        for ( int j = 0; j < realSize; j++) {
            delete(board_[i][j]);
        }
    }
}

void Board::placeWall() {

    Wall * temp;
    int x, y;
    char piv;

    std::cout << "Indiquez l'horizontale :";
    y = getInt();
    std::cout << std::endl;
    std::cout << "Indiquez la verticale :";
    x = getInt();
    std::cout << std::endl;
    std::cout << "Horizontale ou Verticale?";
    std::cin >> piv;
    std::cout << std::endl;

    x = (x * 2) - 1;
    y = (y * 2) - 1;

    if (piv == 'V' || piv == 'v') {
        for (int i = -1; i < 2; i++) {
            temp = (Wall *) board_[x + i][y];
            temp->build();

        }
    }
    else if ((piv == 'H' || piv == 'h')) {
        for (int i = -1; i < 2; i++) {
            temp = (Wall *) board_[x][y + i];
            temp->build();

        }
    }
}
int Board::getInt() {
    int x;
    while (true) {
        std::cout << "Entrer un entier !" << std::endl;
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cin >> x;
        if (!std::cin.fail()) {
            return x;
        }
    }
}
