#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial{
private:
    int coefficient;
    int exponent;
public:
    explicit Polynomial(int=1,int=1);
    Polynomial(Polynomial&);
    friend std::ostream& operator<<(std::ostream&,Polynomial&);
    int getEfficient();
    int getExponent();
    void setEfficient(int);
    void setExponent(int);
    Polynomial operator+(Polynomial&) const;
    Polynomial operator-(Polynomial&) const;
    Polynomial operator*(Polynomial&) const;
    Polynomial operator/(Polynomial&) const;
};

#endif

