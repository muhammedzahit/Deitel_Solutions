#ifndef ARRAY_H
#define ARRAY_H

class chessBoard{
private:
    int row;
    int column;
    int *ptr;
public:
    explicit chessBoard(int=1,int=1);
    void printBoard();
    int getRow();
    int getChessMan(int);
    void changeChessMan(int,int);
    int operator()(int a,int b) const;
    int &operator()(int,int);
    friend std::ostream& operator<<(std::ostream&,chessBoard&);
    bool operator==(chessBoard&);
    bool operator!=(chessBoard&);
    void operator=(chessBoard&);
};


#endif
