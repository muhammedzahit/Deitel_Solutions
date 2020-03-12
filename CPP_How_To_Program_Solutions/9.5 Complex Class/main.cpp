#include <iostream>
#include "complex.hpp"
using namespace std;
int main(){
    Complex complex1(1,2);
    Complex complex2(3,4);
    cout << "Initial State" << endl;
    complex1.print();
    complex2.print();
    complex1.add(complex1,complex2);
    cout << "added complex2 to complex1" << endl;
    complex1.print();
    complex2.print();
    complex2.substract(complex2,complex1);
    cout << endl << "substracted complex1 to complex2" << endl;
    complex1.print();
    complex2.print();
    return 0;
}