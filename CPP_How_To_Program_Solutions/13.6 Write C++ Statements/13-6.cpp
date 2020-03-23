#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    /* Print integer 40000 left justified in a 15-digit field*/
    int x;
    char b[30];
    x = 40000;
    cout << left << setw(15) << x << endl;

    /*Read a string into character array variable state.*/
    cout << endl;
    cout << "Enter a string -> " ;
    cin.getline(b,30);
    cout << b << endl;

    /*Print 200 with and without a sign.*/
    cout << endl;
    x = 200;
    cout << showpos << x << " " <<  noshowpos << x << endl;

    /* Print the decimal value 100 in hexadecimal form preceded by 0x */
    cout << endl;
    x = 100;
    cout << hex << showbase << x << dec << endl;

    /* Read characters into array charArray until the character 'p' is encountered, up to a limit of 10 characters
    (including the terminating null character). Extract the delimiter from the input stream, and discard it */
    cout << endl;
    cout << "Enter a string -> " ;
    char temp;
    char c[10];
    for (int i=0; i<10 ; i++){
        temp = cin.get();
        if (temp == '\0' || i == 9){ c[i] = temp; break; }
        if (temp == 'p'){ c[i] = '\0'; break; }
        c[i] = temp;
    }
    for (int i=0; i<10; i++){
        if (c[i] == '\0') break;
        else cout << c[i];
    }
    cin.ignore(256,'\n');
    cout << endl;

    /* Print 1.234 in a 9-digit field with preceding zeros. */
    cout << endl;
    double y = 1.234;
    cout.precision(9);
    cout << fixed << y << endl;
    return 0;
}
