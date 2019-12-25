#ifndef CRATE_H
#define CRATE_H
#include <string>
class staff{
public:
    staff(int,std::string);
    ~staff();
private:
    int ObjectID;
    std::string name;
};

#endif