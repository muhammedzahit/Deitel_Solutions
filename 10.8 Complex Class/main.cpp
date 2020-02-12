#include <iostream>
#include "complex.h"
using namespace std;
int main(){
    Complex x;
    Complex y;
    Complex z;
    cin >> x;
    cin >> y;
    cout << "x:" << x;
    cout << "y:" << y;
    z = x*y;
    cout << "Multiplication: " << z;
    if (x == y){
        cout << "Equal " << endl;
    }
    else cout << "Not Equal " << endl;
    return 0;
}