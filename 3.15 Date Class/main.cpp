#include "date.h"
using namespace std;
int main(){
    date a(29,2,2000);
    a.displayDate();
    date b(30,2,2000);
    b.displayDate();
    date c(28,2,2001);
    c.displayDate();
    date d(29,2,2001);
    d.displayDate();
    date e(31,1,2000);
    e.displayDate();
    date f(32,1,2000);
    f.displayDate();
    
    return 0;
}