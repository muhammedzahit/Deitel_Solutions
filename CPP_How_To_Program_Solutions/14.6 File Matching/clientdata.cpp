#include "clientdata.h"

ClientData::ClientData(int a, std::string b, std::string c, double d)
    : accountNumber(a), balance(d)
{
    setLastName(c);setFirstName(b);
}

void ClientData::setAccountNumber(const int & a) {
    accountNumber = a;
}

void ClientData::setLastName(const std::string & b) {
    int length = b.length();
    length = (length < 15 ? length:14);
    b.copy(lastName,length);
    lastName[length] = '\0';
}

void ClientData::setFirstName(const std::string & b) {
    int length = b.length();
    length = (length < 10 ? length:9);
    b.copy(firstName,length);
    firstName[length] = '\0';
}

void ClientData::setBalance(const double & b) {
    balance = b;
}

int ClientData::getAccountNumber() const {
    return accountNumber;
}

std::string ClientData::getLastName() const {
    return std::__cxx11::string(lastName);
}

std::string ClientData::getFirstName() const {
    return std::__cxx11::string(firstName);
}

double ClientData::getBalance() const {
    return balance;
}

std::ostream &operator<<(std::ostream & cout, ClientData & c) {
    cout << "Musteri no: " << c.getAccountNumber() << std::endl;
    cout << "Ad : " << c.getFirstName() << std::endl;
    cout << "Soyad : "<< c.getLastName() << std::endl;
    cout << "Bakiye : "<< c.getBalance() << std::endl;
    return cout;
}

