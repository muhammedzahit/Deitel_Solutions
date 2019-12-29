#ifndef MULTIPLE_H
#define MULTIPLE_H
#include "hugeinteger.hpp"
class multiple{
    long double value=0.0;
    HugeInteger first;
    HugeInteger second;
public:
    void calculate(HugeInteger&,HugeInteger&);
};

#endif

