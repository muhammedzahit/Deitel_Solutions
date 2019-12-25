#include <iostream>
#include "crate.h"
using namespace std;
staff staff1(1,"global");
void crate(){
    staff staff2(2,"in function");
    static staff staff3(3,"in function but static");
}

int main(){
    staff staff4(4,"normal");
    crate();
    staff staff5(5,"after crate func");
    return 0;
}
