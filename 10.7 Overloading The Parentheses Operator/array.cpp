#include <iostream>
#include "array.h"
using namespace std;
chessBoard::chessBoard(int n_row,int n_column)
    : row(n_row) , column(n_column)
{
    ptr = new int[row*column] {0};
}

void chessBoard::printBoard() {
    for (int i=0; i<row*column; i++){
        cout << ptr[i] << " ";
        if (((i+1) % row) == 0){
            cout << endl;
        }
    }
}

void chessBoard::changeChessMan(int n_row, int n_column) {
    if (n_row > row || n_column > column){
        throw invalid_argument("You overstep board !!!");
    }
    if (n_row < 0 || n_column < 0){
        throw invalid_argument("You overstep board !!!");
    }
    int location = (n_row-1) * row;
    int value;
    location += n_column - 1;
    cout << "Enter new value of chessman : " ;
    cin >> value;
    ptr[location] = value;
    cout << endl;
}

int chessBoard::getRow() {
    return row;
}

int chessBoard::getChessMan(int lct) {
    return ptr[lct];
}

int chessBoard::operator()(int a, int b) const {
    if (a > row || b > column){
        throw invalid_argument("You overstep board !!!");
    }
    if (a < 0 || b < 0){
        throw invalid_argument("You overstep board !!!");
    }
    int location = (a-1)*row;
    location += b-1;
    return ptr[location];
}

int &chessBoard::operator()(int a, int b) {
    if (a > row || b > column){
        throw invalid_argument("You overstep board !!!");
    }
    if (a < 0 || b < 0){
        throw invalid_argument("You overstep board !!!");
    }
    int location = (a-1)*row;
    location += b-1;
    return ptr[location];
}

std::ostream &operator<<(std::ostream &output, chessBoard &cls) {
    cls.printBoard();
    return output;
}

bool chessBoard::operator==(chessBoard &right) {
    if ((row*column) != right.row * right.column) return false;
    for (int i=0; i<row*column; i++){
        if (ptr[i] != right.ptr[i]) return false;
    }
    return true;
}

bool chessBoard::operator!=(chessBoard &right) {
    return !(operator==(right));
}

void chessBoard::operator=(chessBoard &right) {
    if ((row*column) != right.row * right.column) throw invalid_argument("Sizes doesnt match !");
    for (int i=0; i<row*column; i++){
        ptr[i] = right.ptr[i];
    }
}
