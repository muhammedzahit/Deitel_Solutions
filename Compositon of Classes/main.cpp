#include <iostream>
#include "date.h"
#include "employee.h"
using namespace std;
// examples of composition
int main(){
    date date1(26,7,2000);
    info staff1("ahmed","zahid",date1);
    staff1.printInfo();
    return 0;
}