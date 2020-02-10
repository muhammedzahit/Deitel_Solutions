#include <iostream>
#include "array.h"
using namespace std;
int main(){
    chessBoard board1(2,2);
    chessBoard board2(2,2);
    if (board1 == board2){
        cout << "equal" << endl;
    }
    board1.changeChessMan(1,1);
    if (board1 != board2){
        cout << "not equal" << endl;
    }
    cout << board1;
    cout << board2;
    board2 = board1;
    cout << board1;
    cout << board2;
    return 0;
}