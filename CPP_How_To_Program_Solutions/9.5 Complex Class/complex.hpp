#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
class Complex{
private:
    double realPart;
    double imaginaryPart;
public:
    Complex(double=0.0,double=0.0);
    void add(Complex&,Complex&);
    void substract(Complex&,Complex&);
    void print();
};



#endif