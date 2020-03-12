#include <iostream>
#include "rectangle.hpp"
using namespace std;

int main(){

    Rectangle rectangle1(99.0,99.0);
    rectangle1.printInfo();
    Rectangle rectangle2(12.3,14.5);
    rectangle2.printInfo();

    return 0;
}