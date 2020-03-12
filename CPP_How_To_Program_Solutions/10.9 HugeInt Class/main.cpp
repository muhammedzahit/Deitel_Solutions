#include <iostream>
#include "hugeint.h"
using namespace std;
int main(){
    h_int a("21321432423432");
    h_int b("123212133434");
    h_int c = a+b;
    h_int d = a*b;
    h_int e = a/b;
    cout << d;
    cout << c;
    cout << e;
    return 0;
}