#include "hugeinteger.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <math.h>
using namespace std;
unsigned long long int i = pow(10.0,10.0);
HugeInteger::HugeInteger(string number){
    if (number.size() <= 10){
        stringstream token(number);
        token >> first10;
        size = number.size();
    }
    else if (number.size() <= 20){
        int len = number.size();
        size = len;
        string first(number,len-10,10);
        stringstream token1(first);
        token1 >> first10;
        string second(number,0,len-10);
        stringstream token2(second);
        token2 >> second10;
    }
    else if (number.size() <= 30){
        int len = number.size();
        size = len;
        string first(number,len-20,10);
        stringstream t1(first);
        t1 >> first10;
        string second(number,len-10,10);
        stringstream t2(second);
        t2 >> second10;
        string third(number,0,len-20);
        stringstream t3(third);
        t3 >> third10;
    }
    else if(number.size() <= 40){
        int len = number.size();
        size = len;
        string first(number,len-30,10);
        stringstream t1(first);
        t1 >> first10;
        string second(number,len-20,10);
        stringstream t2(second);
        t2 >> second10;
        string third(number,len-10,10);
        stringstream t3(third);
        t3 >> third10;
        string last(number,0,len-30);
        stringstream t4(last);
        t4 >> last10;
    }
    else{
        throw invalid_argument("Fault : Number must be under 41 digits !");
    }
}

void HugeInteger::printNum(){
    if (second10 == 0){
        cout << first10 << endl;
    }
    else if (third10 == 0){
        cout << second10 << first10 << endl;
    }
    else if (last10 == 0){
        cout << third10 << second10 << first10 << endl;
    }
    else {
        cout << last10 << third10 << second10 << first10 << endl;
    }
}

bool HugeInteger::isEqualTo(HugeInteger& first,HugeInteger& second){
    if ( (first.size) != (second.size) ){
        return false;
    }
    else {
        if (first.last10 == 0 && first.third10 == 0 && first.second10 == 0){
            if (first.first10 == second.first10) return true;
            else return false;
        }
        else if (first.last10 == 0 && first.third10 == 0){
            if (first.first10 == second.first10 && first.second10 == second.second10) return true;
            else return false;
        }
        else if (first.last10 == 0){
            if (first.first10 == second.first10 && 
                first.second10 == second.second10 && 
                first.third10 == second.third10
                ) return true;
            else return false;
        }
        else {
            if (first.first10 == second.first10 && 
                first.second10 == second.second10 && 
                first.third10 == second.third10 && 
                first.last10 == second.last10 
                ) return true;
            else return false;
        }
    }
}


bool HugeInteger::isGraterThan(HugeInteger& first,HugeInteger& second){
    if ( (first.size) > (second.size) ){
        return true;
    }
    else if ( (first.size) < (second.size) ){
        return false;
    }
    else {
        if (first.last10 == 0 && first.third10 == 0 && first.second10 == 0){
            if (first.first10 > second.first10) return true;
            else if (first.first10 == second.first10){
                return false;
                cout << endl << "Numbers are equal" << endl;
            }
            else return false;
        }
        else if (first.last10 == 0 && first.third10 == 0){
            if (first.second10 > second.second10) return true;
            else if (first.second10 < second.second10 ) return false;
            else {
                if (first.first10 > second.first10) return true;
                else if (first.first10 == second.first10){
                    return false;
                    cout << endl << "Numbers are equal" << endl;
                }
                else return false;
            }
        }
        else if (first.last10 == 0){
            if (first.third10 > second.third10) return true;
            else if (first.third10 < second.third10) return false;
            else{
                if (first.second10 > second.second10) return true;
                else if (first.second10 < second.second10 ) return false;
                else {
                    if (first.first10 > second.first10) return true;
                    else if (first.first10 == second.first10){
                        return false;
                        cout << endl << "Numbers are equal" << endl;
                    }
                    else return false;
                }
            }
        }
        else {
            if (first.last10 > second.last10) return true;
            else if(first.last10 < second.last10) return false;
            else{
                if (first.third10 > second.third10) return true;
                else if (first.third10 < second.third10) return false;
                else{
                    if (first.second10 > second.second10) return true;
                    else if (first.second10 < second.second10 ) return false;
                    else {
                        if (first.first10 > second.first10) return true;
                        else if (first.first10 == second.first10){
                            return false;
                            cout << endl << "Numbers are equal" << endl;
                        }
                        else return false;
                    }
                }
            }
        }
    }
}


bool HugeInteger::isLessThan(HugeInteger& first,HugeInteger& second){
    if ( (first.size) < (second.size) ){
        return true;
    }
    else if ( (first.size) > (second.size) ){
        return false;
    }
    else {
        if (first.last10 == 0 && first.third10 == 0 && first.second10 == 0){
            if (first.first10 < second.first10) return true;
            else if (first.first10 == second.first10){
                return false;
                cout << endl << "Numbers are equal" << endl;
            }
            else return false;
        }
        else if (first.last10 == 0 && first.third10 == 0){
            if (first.second10 < second.second10) return true;
            else if (first.second10 > second.second10 ) return false;
            else {
                if (first.first10 < second.first10) return true;
                else if (first.first10 == second.first10){
                    return false;
                    cout << endl << "Numbers are equal" << endl;
                }
                else return false;
            }
        }
        else if (first.last10 == 0){
            if (first.third10 < second.third10) return true;
            else if (first.third10 > second.third10) return false;
            else{
                if (first.second10 < second.second10) return true;
                else if (first.second10 > second.second10 ) return false;
                else {
                    if (first.first10 < second.first10) return true;
                    else if (first.first10 == second.first10){
                        return false;
                        cout << endl << "Numbers are equal" << endl;
                    }
                    else return false;
                }
            }
        }
        else {
            if (first.last10 < second.last10) return true;
            else if(first.last10 > second.last10) return false;
            else{
                if (first.third10 < second.third10) return true;
                else if (first.third10 > second.third10) return false;
                else{
                    if (first.second10 < second.second10) return true;
                    else if (first.second10 > second.second10 ) return false;
                    else {
                        if (first.first10 < second.first10) return true;
                        else if (first.first10 == second.first10){
                            return false;
                            cout << endl << "Numbers are equal" << endl;
                        }
                        else return false;
                    }
                }
            }
        }
    }
}

unsigned long long int HugeInteger::getFirst10(){
    return first10;
}
unsigned long long int HugeInteger::getSecond10(){
    return second10;
}
unsigned long long int HugeInteger::getThird10(){
    return third10;
}
unsigned long long int HugeInteger::getLast10(){
    return last10;
}

void HugeInteger::setFirst10(unsigned long long int a){
    first10 += a;
    if (first10 > i){
        first10 %= i;
        second10 += 1;
    }
}
void HugeInteger::setSecond10(unsigned long long int a){
    second10 += a;
    if (second10 > i){
        second10 %= i;
        first10 += 1;
    }
}
void HugeInteger::setThird10(unsigned long long int a){
    third10 += a;
    if (third10 > i){
        third10 %= i;
        last10 += 1;
    }
}
void HugeInteger::setLast10(unsigned long long int a){
    last10 += a;
}