#include <iostream>
#include <math.h>
#include <iomanip>
#include "hugeinteger.hpp"
#include "multiple.hpp"
using namespace std;


void multiple::calculate(HugeInteger& a,HugeInteger& b){

    unsigned long long int afirst5,asecond5,bfirst5,bsecond5,i,islem1,islem2,islem3;

    afirst5 = 0;
    asecond5 = 0;
    bfirst5 = 0;
    bsecond5 = 0;
    i = pow(10.0,5.0);
    afirst5 = a.getFirst10()% i ;
    asecond5 = a.getFirst10()/ i ;
    bfirst5 = b.getLast10()%i;
    bsecond5 = b.getLast10()/i;
    islem1,islem2,islem3;
    islem1 = a.getFirst10() * bsecond5;
    islem2 = a.getFirst10() * bfirst5;
    i = pow(10.0,10.0);
    islem3 = islem1 % i;
    i = pow(10.0,5.0);
    islem3 *= i;
    cout << endl <<islem3 << endl;
    islem2 += islem3;
    i = pow(10.0,9.0);
    islem1 /= i;
    i = pow(10.0,14.0);
    if (islem2 > i){
        islem2 -= i;
        islem1 += 1;
    }
    i = pow(10.0,4.0);
    islem1 *= i;
    i = pow(10.0,10.0);
    islem1 += islem2 / i;
    islem2 %= i;
    cout << endl << endl << islem1 << "  " << islem2 << endl;
    second.setFirst10(islem1);
    first.setLast10(islem2);

    afirst5 = 0;
    asecond5 = 0;
    bfirst5 = 0;
    bsecond5 = 0;
    i = pow(10.0,5.0);
    afirst5 = a.getFirst10()% i ;
    asecond5 = a.getFirst10()/ i ;
    bfirst5 = b.getThird10()%i;
    bsecond5 = b.getThird10()/i;
    islem1,islem2,islem3;
    islem1 = a.getFirst10() * bsecond5;
    islem2 = a.getFirst10() * bfirst5;
    i = pow(10.0,10.0);
    islem3 = islem1 % i;
    i = pow(10.0,5.0);
    islem3 *= i;
    cout << endl <<islem3 << endl;
    islem2 += islem3;
    i = pow(10.0,9.0);
    islem1 /= i;
    i = pow(10.0,14.0);
    if (islem2 > i){
        islem2 -= i;
        islem1 += 1;
    }
    i = pow(10.0,4.0);
    islem1 *= i;
    i = pow(10.0,10.0);
    islem1 += islem2 / i;
    islem2 %= i;
    cout << endl << endl << islem1 << "  " << islem2 << endl;
    first.setLast10(islem1);
    first.setThird10(islem2);
    
    afirst5 = 0;
    asecond5 = 0;
    bfirst5 = 0;
    bsecond5 = 0;
    i = pow(10.0,5.0);
    afirst5 = a.getFirst10()% i ;
    asecond5 = a.getFirst10()/ i ;
    bfirst5 = b.getSecond10()%i;
    bsecond5 = b.getSecond10()/i;
    islem1,islem2,islem3;
    islem1 = a.getFirst10() * bsecond5;
    islem2 = a.getFirst10() * bfirst5;
    i = pow(10.0,10.0);
    islem3 = islem1 % i;
    i = pow(10.0,5.0);
    islem3 *= i;
    cout << endl <<islem3 << endl;
    islem2 += islem3;
    i = pow(10.0,9.0);
    islem1 /= i;
    i = pow(10.0,14.0);
    if (islem2 > i){
        islem2 -= i;
        islem1 += 1;
    }
    i = pow(10.0,4.0);
    islem1 *= i;
    i = pow(10.0,10.0);
    islem1 += islem2 / i;
    islem2 %= i;
    cout << endl << endl << islem1 << "  " << islem2 << endl;
    first.setThird10(islem1);
    first.setSecond10(islem2);

    afirst5 = 0;
    asecond5 = 0;
    bfirst5 = 0;
    bsecond5 = 0;
    i = pow(10.0,5.0);
    afirst5 = a.getFirst10()% i ;
    asecond5 = a.getFirst10()/ i ;
    bfirst5 = b.getFirst10() % i;
    bsecond5 = b.getFirst10() / i;
    islem1,islem2,islem3;
    islem1 = a.getFirst10() * bsecond5;
    islem2 = a.getFirst10() * bfirst5;
    i = pow(10.0,10.0);
    islem3 = islem1 % i;
    i = pow(10.0,5.0);
    islem3 *= i;
    cout << endl <<islem3 << endl;
    islem2 += islem3;
    i = pow(10.0,9.0);
    islem1 /= i;
    i = pow(10.0,14.0);
    if (islem2 > i){
        islem2 -= i;
        islem1 += 1;
    }
    i = pow(10.0,4.0);
    islem1 *= i;
    i = pow(10.0,10.0);
    islem1 += islem2 / i;
    islem2 %= i;
    cout << endl << endl << islem1 << "  " << islem2 << endl;
    first.setSecond10(islem1);
    first.setFirst10(islem2);

    cout << second.getFirst10() << " " <<first.getLast10() << " " << first.getThird10() << " " << first.getSecond10() << " " << first.getFirst10() << endl;
}