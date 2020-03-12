// AN EXAMPLE OF CASCADED FUNCTIONS IN A CLASS
#include <iostream>
#include "calisan.h"
using namespace std;
int main(){
    calisan calisan1;
    calisan1.printInfo();
    calisan1.setName("Ahmed").setLastName("Yavuz").setSalary(3000).setNumber(1).printInfo();
    return 0;
}