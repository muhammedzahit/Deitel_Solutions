#ifndef C___TRANSACTION_H
#define C___TRANSACTION_H

#include <string>
#include <stack>

class Transaction {
private:
    int i;
    int accountNumber;
public:
    char islemler[1000];
    Transaction() :accountNumber(0) , i(0){
    }
    int getNum() const;
    void setNum(const int&);
    void islemEkle(const std::string &);
};


#endif //C___TRANSACTION_H
