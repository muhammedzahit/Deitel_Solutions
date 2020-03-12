#include <iostream>
#include "multiple.hpp"
#include "hugeinteger.hpp"
using namespace std;

HugeInteger generateHugeNum(){
    string number;
    cout << "Enter a number :" ; 
    cin >> number;
    cout << number.size() << endl;
    HugeInteger newInt(number);
    return newInt;
}

int main(){

    HugeInteger number1 = generateHugeNum();
    number1.printNum();
    HugeInteger number2 = generateHugeNum();
    number2.printNum();
    number1.isEqualTo(number1,number2) ? cout << "Equal" : cout << "Not Equal" ;
    cout << endl;
    number1.isGraterThan(number1,number2) ? cout << "Greater" : cout << "Not Greater";
    cout << endl;
    number1.isLessThan(number1,number2) ? cout << "Less " : cout << "Not Less" ;
    multiple a;
    a.calculate(number1,number2);
}   