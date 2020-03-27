#include "transaction.h"

int Transaction::getNum() const {
    return accountNumber;
}

void Transaction::setNum(const int& a) {
    accountNumber = a;
}

void Transaction::islemEkle(const std::string & b) {
    int s;
    for (s = 0; s < b.length() ; s++){
        islemler[i+s] = b[s];
    }
    i += s;
    islemler[i] = '\n';
    islemler[++i] = '\0';
}

