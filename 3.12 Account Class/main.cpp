#include "bank.h"
using namespace std;
int main(){
    cout << "Do you have account ?(yes/no)" << endl;
    bank bank2(0);
    string control; int balance;
    cin >> control;
    if (control == "yes"){

    }
    else{
        cout << "Enter your balance :";
        cin >> balance;
        bank bank3(balance);
        bank2 = bank3;
        bank2.control();
    }
    cout << "1-Show balance" << endl;
    cout << "2-Add balance" << endl;
    cout << "3-Withdraw balance" << endl;
    cout << "9-Exit" << endl;
    int flag=1,selection;
    while(flag){
        cout << "Selection:";
        cin >> selection;
        switch (selection){
            case 1:
                bank2.showBalance();
                break;
            case 2:
                bank2.addBalance();
                break;
            case 3:
                bank2.withdrawBalance();
                break;
            case 9:
                flag = 0;
                break;
        }
    }
    return 0;
}