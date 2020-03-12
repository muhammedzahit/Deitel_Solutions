#include <iostream>
#include "tic_tac_toe.hpp"
using namespace std;

int main(){
    char user_char;
    int user_number,move_number;
    cout << "Movemont numbers of board:" << endl;
    for (int i = 1; i<=9; i++){
        cout << i << " " ;
        if (i % 3 == 0) cout << endl;
    }
    cout << "Pick your game character(X/O)" << endl;
    cin >> user_char;
    if (user_char == 'X') user_number = 1;
    else user_number = 2;
    Board board1(user_number);
    board1.printBoard();
    while (board1.getGameStatus()){
        cout << "Enter your movement:";
        cin >> move_number;
        board1.setBoard(move_number);
        board1.computerMove();
        board1.printBoard();
        board1.check();
    }
    board1.winnerIs();
}