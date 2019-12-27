#ifndef RATIONAL_H
#define RATIONAL_H

class Rational{
private:
    int numerator;
    int denominator;
public:
    Rational(int=1,int=1);
    Rational addRationals(Rational&,Rational&);
    Rational substractRationals(Rational&,Rational&);
    Rational multiplyRationals(Rational&,Rational&);
    Rational divideRationals(Rational&,Rational&);
    void printRational();
    void printValue();
};

#endif