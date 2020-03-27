#ifndef C___CLIENTDATA_H
#define C___CLIENTDATA_H

#include <string>
#include <iostream>
class ClientData {
private:
    int accountNumber;
    char lastName[15];
    char firstName[10];
    double balance;
public:
    ClientData(int=0,std::string = " ",std::string = " ",double = 0.0);
    void setAccountNumber(const int&);
    void setLastName(const std::string&);
    void setFirstName(const std::string&);
    void setBalance(const double&);
    int getAccountNumber() const;
    std::string getLastName() const;
    std::string getFirstName() const;
    double getBalance() const;
    friend std::ostream& operator<<(std::ostream&,ClientData&);
};


#endif
