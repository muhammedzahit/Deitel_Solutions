#ifndef MARTIAN_HPP
#define MARTIAN_HPP

#include <iostream>

class martian{
private:
    std::string name;
    static int count;
public:
    martian(std::string);
    void printCount();
};

#endif
