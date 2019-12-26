#include <string>
#include "date.h"
class info{
private:
    std::string name;
    std::string lastname;
    date birth;
public:
    info(std::string,std::string,date);
    void printInfo();
};