#include "bank.h"
using namespace std;
bank::bank(int initial) : balance(initial) {};
void bank::control() {
    if (balance < 0){
        cerr << "You entered wrong value !" << endl;
        cout << "Balance = 0" << endl;
        balance = 0;
    }
}
void bank::showBalance() const {
    cout << "Balance = " << balance << endl;
}
int bank::getBalance() const {
    return balance;
}
void bank::addBalance() {
    int add;
    cout << "Enter money mount you will add : ";
    cin >> add;
    balance += add;
}
void bank::withdrawBalance() {
    int minus;
    cout << "Enter money mount you will withdraw : ";
    cin >> minus;
    balance -= minus;
}
