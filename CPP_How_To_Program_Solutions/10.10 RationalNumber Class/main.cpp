#include <iostream>
#include "rational.h"
using namespace std;
int main(){
    Rational a(12,4);
    Rational b(6,4);
    Rational c = a * b;
    Rational d = a / b;
    Rational e = a + b;
    Rational f = a - b;
    cout << a;
    cout << b;
    cout << "After simplification " << endl;
    a.simplification();
    b.simplification();
    cout << a;
    cout << b;
    cout << "* :" << c;
    cout << "/ :" << d;
    cout << "+ :" << e;
    cout << "- :" << f;
    return 0;
}