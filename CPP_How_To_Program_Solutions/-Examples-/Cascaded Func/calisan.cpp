#include <iostream>
#include "calisan.h"
using namespace std;
int calisan::getSalary(){
    return maas;
}
int calisan::getNumber(){
    return no;
}
string calisan::getName(){
    return isim;
}
string calisan::getLastName(){
    return soyisim;
}
calisan& calisan::setSalary(int salary){
    maas = salary;
    return *this;
}
calisan& calisan::setNumber(int number){
    no = number;
    return *this;
}
calisan& calisan::setName(string name){
    isim = name;
    return *this;
}
calisan& calisan::setLastName(string lastName){
    soyisim = lastName;
    return *this;
}
calisan::calisan(int salary,int number,string name,string lastName)
    : maas(salary) , no(number) , isim(name) , soyisim (lastName) {}
void calisan::printInfo(){
    cout << endl <<"isim: " << isim << endl;
    cout << "Soyisim: " << soyisim << endl;
    cout << "Calisan NO: " << no << endl;
    cout << "Maas: " << maas << endl << endl;
}