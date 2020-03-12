#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
#include <array>
class h_int{
public:
    static const int digits = 30;
    h_int(const std::string &);
    friend std::ostream& operator<<(std::ostream&,h_int&);
    h_int operator+(h_int &) const;
    h_int operator*(h_int &) const;
    h_int operator/(h_int &) const;
private:
    std::array<short,digits> integer;

};

#endif