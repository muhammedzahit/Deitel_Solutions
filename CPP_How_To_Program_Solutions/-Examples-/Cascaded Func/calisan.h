#ifndef CALISAN_H
#define CALISAN_H
#include <iostream>
class calisan{
private:
    int maas;
    int no;
    std::string isim;
    std::string soyisim;
public:
    explicit calisan(int=0,int=0,std::string="???",std::string="???");
    void printInfo();
    int getSalary();
    int getNumber();
    std::string getName();
    std::string getLastName();
    calisan &setSalary(int);
    calisan &setNumber(int);
    calisan &setName(std::string);
    calisan &setLastName(std::string);
};

#endif

