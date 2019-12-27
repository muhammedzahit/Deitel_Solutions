#include <iostream>
#include "rational.hpp"
using namespace std;

void reduce(int *numerator,int *denominator){
    int i,small;
    if (*numerator % *denominator == 0){
        *numerator /= *denominator;
        *denominator = 1;
    }
    *denominator > *numerator ? small = *numerator : small = *denominator;
    for (i=2 ; i<=small ; i++){
        if (*denominator % i == 0 && *numerator % i == 0){
            *denominator /= i;
            *numerator /= i;
            *denominator > *numerator ? small = *numerator : small = *denominator;
        }
    }   
}

Rational::Rational(int Numerator,int Denominator)
    :numerator(Numerator) , denominator(Denominator) 
{
    reduce(&numerator,&denominator);
}

void Rational::printRational(){
    cout << numerator << "/" << denominator << endl;
}

Rational Rational::addRationals(Rational& first,Rational& second){
    int a,b,c;
    // a/b + c/d
    a = first.numerator * second.denominator;
    b = first.denominator * second.denominator;
    c = first.denominator * second.numerator;
    a += c;
    Rational newR(a,b);
    return newR;
}

Rational Rational::substractRationals(Rational& first,Rational& second){
    int a,b,c;
    // a/b - c/d
    a = first.numerator * second.denominator;
    b = first.denominator * second.denominator;
    c = first.denominator * second.numerator;
    a -= c;
    Rational newR(a,b);
    return newR;
}

Rational Rational::multiplyRationals(Rational& first,Rational& second){
    int a,b;
    // a/b * c/d
    a = first.numerator * second.numerator;
    b = first.denominator * second.denominator;
    Rational newR(a,b);
    return newR;
}

Rational Rational::divideRationals(Rational& first,Rational& second){
    int a,b;
    // a/b / c/d
    a = first.numerator * second.denominator;
    b = first.denominator * second.numerator;
    Rational newR(a,b);
    return newR;
}

void Rational::printValue(){
    double value;
    value = (double)numerator / denominator;
    cout << value << endl;
}