#include <iostream>
using namespace std;

int main(){
    for (int i=33 ; i<127; i++){
        char a = i;
        cout << endl << "Character : " << a << endl;
        cout << "Decimal value : " << i << endl;
        cout << "Hexadecimal value : " << hex << showbase << i << endl;
        cout << "Octal Value : " << oct << i << dec << endl;
    }
    return 0;
}
