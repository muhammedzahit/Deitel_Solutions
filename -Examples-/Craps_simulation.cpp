#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;
int rollDice(){
    int a,b;
    a = rand()%6+1;
    b = rand()%6+1;
    return a+b;
}
int main(){
    srand(time(NULL));
    enum Status{LOSE,CONTINUE,WON};
    Status gameStatus = CONTINUE;
    int i,s;
    i = rollDice();
    cout << "Your point is " << i << endl;
    switch (i){
        case 7:
        case 11:
            gameStatus = WON;
            cout << "You won the game!" << endl;
            break;
        case 2:
        case 3:
        case 12:
            gameStatus = LOSE;
            cout << "You lose the game!" << endl;
            break;
        default:
            break;
    }
    while (gameStatus == CONTINUE){
        s = rollDice();
        if (s == i){
            gameStatus = WON;
            getch();
            cout << "Sum of dice is " << s << endl;
            cout << "You won the game!" << endl;
        }
        else if (s == 7){
            gameStatus = LOSE;
            getch();
            cout << "Sum of dice is " << s << endl;
            cout << "You lose the game!" << endl;
        }
        else {
            getch();
            cout << "Sum of dice is " << s << endl;
        }
    }
    return 0;
}