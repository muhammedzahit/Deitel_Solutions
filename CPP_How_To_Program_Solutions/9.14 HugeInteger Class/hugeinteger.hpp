#ifndef HUGEINTEGER_HPP
#define HUGEINTEGER_HPP
#include <iostream>
class HugeInteger{
public:
    HugeInteger(std::string="0");
    void printNum();
    bool isEqualTo(HugeInteger&,HugeInteger&);
    bool isGraterThan(HugeInteger&,HugeInteger&);
    bool isLessThan(HugeInteger&,HugeInteger&);
    unsigned long long int getFirst10();
    unsigned long long int getSecond10();
    unsigned long long int getThird10();
    unsigned long long int getLast10();
    void setFirst10(unsigned long long int);
    void setSecond10(unsigned long long int);
    void setThird10(unsigned long long int);
    void setLast10(unsigned long long int);
private:
    unsigned long long int first10=0;
    unsigned long long int second10=0;
    unsigned long long int third10=0;
    unsigned long long int last10=0;
    int size;
};

#endif
