#include <iostream>
#include "martian.hpp"
using namespace std;
int martian::count = 0;
martian::martian(string nname)
    : name(nname) 
    {
        count++;
    }
void martian::printCount(){
    cout << "Count : " << count << endl;
}