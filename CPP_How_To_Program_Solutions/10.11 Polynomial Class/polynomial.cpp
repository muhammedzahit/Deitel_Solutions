#include <iostream>
#include "polynomial.h"
using namespace std;

Polynomial::Polynomial(int n_co, int n_exp)
    : coefficient(n_co) , exponent(n_exp) {}

std::ostream &operator<<(std::ostream &output, Polynomial &a) {
    output << a.coefficient << "x^" << a.exponent << endl;
    return output;
}

int Polynomial::getEfficient() {
    return coefficient;
}

int Polynomial::getExponent() {
    return exponent;
}

void Polynomial::setEfficient(int a) {
    coefficient = a;
}

void Polynomial::setExponent(int a) {
    exponent = a;
}

Polynomial::Polynomial(Polynomial &right) {
    coefficient = right.coefficient;
    exponent = right.exponent;
}

Polynomial Polynomial::operator+(Polynomial &right) const {
    Polynomial final(1,1);
    if (exponent != right.exponent){
        throw invalid_argument ("Unable to add! Error: Exponent must be same");
    }
    final.setEfficient(coefficient+right.coefficient);
    final.setExponent(exponent);
    return final;
}

Polynomial Polynomial::operator-(Polynomial &right) const {
    Polynomial final(1,1);
    if (exponent != right.exponent){
        throw invalid_argument ("Unable to subtract! Error: Exponent must be same");
    }
    final.setEfficient(coefficient-right.coefficient);
    final.setExponent(exponent);
    return final;
}

Polynomial Polynomial::operator*(Polynomial &right) const {
    Polynomial final(1,1);
    final.setEfficient(coefficient*right.coefficient);
    final.setExponent(exponent+right.exponent);
    return final;
}

Polynomial Polynomial::operator/(Polynomial &right) const {
    Polynomial final(1,1);
    final.setEfficient(coefficient/right.coefficient);
    final.setExponent(exponent-right.exponent);
    return final;
}
