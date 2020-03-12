#ifndef SAVINGS_HPP
#define SAVINGS_HPP

class SavingsAccount{
private:
    static int annualInterest;
    int deposit;
public:
    SavingsAccount(int=0);
    void setInterest(int);
    void applyInterest();
    void printDeposit();
};


#endif
