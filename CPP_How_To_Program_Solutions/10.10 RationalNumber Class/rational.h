#ifndef RATIONAL_H
#define RATIONAL_H

class Rational{
private:
    int nominator;
    int denominator;
public:
    Rational(int=1,int=1);
    friend std::ostream& operator<<(std::ostream&,Rational&);
    void simplification();
    Rational operator*(Rational&) const;
    Rational operator/(Rational&) const;
    Rational operator+(Rational&) const;
    Rational operator-(Rational&) const;
};

#endif

