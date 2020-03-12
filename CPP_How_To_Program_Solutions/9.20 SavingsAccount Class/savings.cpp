#include <iostream>
#include "savings.hpp"
using namespace std;

int SavingsAccount::annualInterest = 3;

void SavingsAccount::setInterest(int a){
    annualInterest = a;
}

SavingsAccount::SavingsAccount(int a){
    if (a < 0){
        cout << "You entered wrong value !!!!" << endl;
        deposit = 0;
    }
    else {
        deposit = a;
    }
}

void SavingsAccount::applyInterest(){
    cout << "How months do you want to put out at interest your deposit ?    ";
    int month_num;
    cin >> month_num;
    while (month_num < 0){
        cout << "You entered wrong value !!! try again" << endl;
        cout << "How months do you want to put out at interest your deposit ?    ";
        cin >> month_num;
    }
    int plus = (deposit*annualInterest*month_num) / 1200;
    deposit += plus;
}

void SavingsAccount::printDeposit(){
    cout << "Your deposit : " << deposit << endl;
}