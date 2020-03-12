#include <iostream>
#include "polynomial.h"
using namespace std;
int main(){
    Polynomial a(2,4);
    Polynomial b(a);
    cout << a;
    cout << b;
    Polynomial c,d,e,f;
    c = a+b;
    d = a-b;
    e = a*b;
    f = a/b;
    cout << c;
    cout << d;
    cout << e;
    cout << f;
    return 0;
}