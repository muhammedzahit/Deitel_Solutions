#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP

#include <iostream>

class Board{
public:
    Board(int);
    void printBoard();
    void setBoard(int);
    bool getGameStatus();
    void check();
    void winnerIs();
    void computerMove();
private:
    int data[3][3];
    int user;
    int computer;
    int counter=0;
    int Winner=3;
    bool gameStatus = true;
};


#endif

