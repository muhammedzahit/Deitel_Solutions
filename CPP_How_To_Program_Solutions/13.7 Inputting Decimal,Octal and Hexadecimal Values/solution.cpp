#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    int x;
    char a,b;
    cout << "Enter a number -> ";
    a = cin.get();
    cout << endl;
    int control = 1;
    if (a == '0'){
        b = cin.get();
        if (b == 'x'){
            cout << "You entered hexadecimal number" << endl;
            control = 2;
        }
        else{
            cin.putback(b);
            cout << "You entered octal number" << endl;
            control = 3;
        }
    }
    else {
        cin.putback(a);
        cout << "You entered decimal number" << endl;
    }
    cout << endl;
    switch(control){
    case 1:
        cin >> x;
        break;
    case 2:
        cin >> hex >> x;
        break;
    case 3:
        cin >> oct >> x;
        break;
    }
    cout << "Decimal form -> " << x << showbase <<  endl;
    cout << "Hexadecimal form -> " << hex << x << endl;
    cout << "Octal form -> " << oct << x << endl;

    return 0;
}
