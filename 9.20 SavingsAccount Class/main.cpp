#include <iostream>
#include "savings.hpp"
using namespace std;

int main(){
    SavingsAccount money1(1000);
    SavingsAccount money2(2000);
    money1.setInterest(5);
    money1.applyInterest();
    money2.applyInterest();
    money1.printDeposit();
    money2.printDeposit();
}