#include <iostream>
#include "tic_tac_toe.hpp"
#include <random>
#include <ctime>
using namespace std;
// int user_number

default_random_engine generator(time(0));
uniform_int_distribution<int> distribution(0,2);

Board::Board(int a)
    : user(a) 
{
    for (int i = 0; i< 3 ; i++){
        for (int s = 0; s<3; s++){
            data[i][s] = 0;
        }
    }
    if (user == 1){
        computer = 2;
    }
    else computer = 1;
}

void Board::printBoard(){
    for (int i = 0; i< 3 ; i++){
        for (int s = 0; s<3; s++){
            if (data[i][s] == 0) cout << "  " ;
            else if (data[i][s] == 1) cout << "X ";
            else cout << "O ";
        }
        cout << endl;
    }
}

bool Board::getGameStatus(){
    return gameStatus;
}
// int movement number
void Board::setBoard(int moveNumber){
    if (counter == 9) return;
    int a = (moveNumber-1)/3;
    int b = moveNumber - (3*a) - 1;
    if (data[a][b] != 0){
        cout << endl << "Fault: Board number is filled !!!" << endl << endl;
        cout << "Enter your movement:";
        int move_number;
        cin >> move_number;
        a = (move_number-1)/3;
        b = move_number - (3*a) - 1;
    }
    data[a][b] = user;
    counter++;
}

void Board::check(){
    if (counter == 9){
        gameStatus = false;
        return;
    } 
    if (data[0][0] != 0 && data[0][0] == data[1][0] && data[1][0] == data[2][0]){
        gameStatus = false;
        Winner = data[0][0];
        return;
    }
    if (data[0][1] != 0 && data[0][1] == data[1][1] && data[1][1] == data[2][1]){
        gameStatus = false;
        Winner = data[0][1];
        return;
    }
    if (data[0][2] != 0 && data[0][2] == data[1][2] && data[1][2] == data[2][2]){
        gameStatus = false;
        Winner = data[0][2];
        return;
    }
    if (data[0][0] != 0 && data[0][0] == data[0][1] && data[0][1] == data[0][2]){
        gameStatus = false;
        Winner = data[0][0];
        return;
    }
    if (data[1][0] != 0 && data[1][0] == data[1][1] && data[1][1] == data[1][2]){
        gameStatus = false;
        Winner = data[1][0];
        return;
    }
    if (data[2][0] != 0 && data[2][0] == data[2][1] && data[2][1] == data[2][2]){
        gameStatus = false;
        Winner = data[2][0];
        return;
    }
    if (data[0][0] != 0 && data[0][0] == data[1][1] && data[1][1] == data[2][2]){
        gameStatus = false;
        Winner = data[0][0];
        return;
    }
}

void Board::winnerIs(){
    if (Winner == user){
        cout << "Congratulations ! You won the game :)" << endl; 
    }
    else if (Winner == computer) {
        cout << "Sorry , You lose the game :(" << endl;
    }
    else {
        cout << "Draw !!! " << endl;
    }
}

void Board::computerMove(){
    if (counter == 9){
        return;
    }
    int x = distribution(generator);
    int y = distribution(generator);
    while (data[x][y] != 0){
        x = distribution(generator);
        y = distribution(generator);
    }
    data[x][y] = computer;
    counter++;
}