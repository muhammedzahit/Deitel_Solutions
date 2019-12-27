#include <iostream>
#include "rational.hpp"
using namespace std;

int main(){

    Rational object1(7,2);
    Rational object2(14,3);
    Rational object3 = object1.addRationals(object1,object2);
    object3.printRational();
    object3.printValue();
    Rational object4 = object1.substractRationals(object1,object2);
    object4.printRational();
    object4.printValue();
    Rational object5 = object1.multiplyRationals(object1,object2);
    object5.printRational();
    object5.printValue();
    Rational object6 = object6.divideRationals(object1,object2);
    object6.printRational();
    object6.printValue();
    return 0;
}