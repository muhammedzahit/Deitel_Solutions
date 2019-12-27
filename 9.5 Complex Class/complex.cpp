#include <iostream>
#include "complex.hpp"
using namespace std;

Complex::Complex(double real,double imagine)
    : realPart(real),imaginaryPart(imagine)
{}

void Complex::add(Complex& first,Complex& second){
    first.realPart += second.realPart;
    first.imaginaryPart += second.imaginaryPart;
}

void Complex::substract(Complex& first,Complex& second){
    first.realPart -= second.realPart;
    first.imaginaryPart -= second.imaginaryPart;
}

void Complex::print(){
    cout << endl <<realPart << "+ " << imaginaryPart << "i" << endl;
}