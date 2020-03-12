#include <iostream>
#include <string>
class bank{
public:
    explicit bank(int initial);
    void control();
    void showBalance() const ;
    int getBalance() const ;
    void addBalance() ;
    void withdrawBalance() ;
private:
    int balance;
};