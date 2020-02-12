#include <iostream>
#include "complex.h"
using namespace std;
Complex::Complex(double real_p, double imaginary_p)
    : real(real_p) , imaginary(imaginary_p)
{}

Complex Complex::operator+(const Complex &right) const {
    return Complex(real+right.real,imaginary+right.imaginary);
}

Complex Complex::operator-(const Complex &right) const {
    return Complex(real-right.real,imaginary-right.imaginary);
}

void Complex::print() const {
    cout << "( " << real << " , " << imaginary << " )" << endl;
}

std::ostream &operator<<(std::ostream &output, Complex &a) {
    output << a.real << " + " << a.imaginary << "i " << endl;
    return output;
}

std::istream &operator>>(std::istream &input, Complex &a) {
    cout << "Real part :" ;
    input >> a.real;
    cout << "Imaginary Part :";
    input >> a.imaginary;
    return input;
}

Complex Complex::operator*(const Complex &right) const {
    return Complex(real*right.real,imaginary*right.imaginary);
}

bool Complex::operator==(const Complex &right) const {
    if ((real == right.real) && (imaginary == right.imaginary)) return true;
    else return false;
}

bool Complex::operator!=(const Complex &right) const {
    return !(*this==right);
}