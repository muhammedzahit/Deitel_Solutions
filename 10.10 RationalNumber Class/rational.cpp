#include <iostream>
#include "rational.h"
using namespace std;
void Rational::simplification() {
    int small = 0;
    bool check = false;
    do{
        check = false;
        if (nominator > denominator) small = denominator;
        else small = nominator;

        for (int i= 2; i<=small; i++){
            if (nominator % i == 0 && denominator % i == 0){
                nominator /= i;
                denominator /= i;
                check = true;
            }
        }
    }while(check);
}

std::ostream &operator<<(std::ostream &output, Rational &a) {
    output << a.nominator << " / " << a.denominator << endl;
    return output;
}

Rational::Rational(int n_nominator, int n_denominator)
    : nominator(n_nominator) , denominator(n_denominator)
{
    if (denominator == 0) throw invalid_argument("Error 404: Divided by zero");
}

Rational Rational::operator*(Rational &r) const {
    Rational final(nominator * r.nominator , denominator * r.denominator);
    final.simplification();
    return final;
}

Rational Rational::operator/(Rational &r) const {
    Rational final(nominator * r.denominator , denominator *r.nominator);
    final.simplification();
    return final;
}

Rational Rational::operator+(Rational &r) const {
    Rational final((nominator*r.denominator) + (r.nominator * denominator) , denominator * r.denominator);
    final.simplification();
    return final;
}

Rational Rational::operator-(Rational &r) const {
    Rational final((nominator*r.denominator) - (r.nominator * denominator) , denominator * r.denominator);
    final.simplification();
    return final;
}