#include <iostream>
#include "integer.hpp"
using namespace std;

IntegerSet::IntegerSet()
     
    {
        for (int i = 0; i<=100 ; i++){
            a[i] = false;
        }
    }

void IntegerSet::put(int a){
    if (a < 0 || a > 100){
        cout << "You must enter number in range 0 and 100 !!!" << endl;
    }
    if (this->a[a] == true){
        cout << "Number is already in list !" << endl;
        return;
    }
    else {
        this->a[a] = true;
    }
}

bool IntegerSet::getNumber(int a){
    return this->a[a];
}

IntegerSet IntegerSet::UnionofSets(IntegerSet& a,IntegerSet& b){
    IntegerSet c;
    c = a;
    for (int i=0; i<= 100 ; i++){
        if (b.a[i] == true) c.a[i] = true;
    }
    return c;
}

IntegerSet IntegerSet::IntersectionOfSets(IntegerSet& a,IntegerSet& b){
    IntegerSet c;
    for (int i=0; i<= 100 ; i++){
        if (a.a[i] == b.a[i]){
            c.a[i] = a.a[i];
        } 
    }
    return c;
}

void IntegerSet::deleteNum(int a){
    if (a < 0 || a > 100){
        cout << "You must enter number in range 0 and 100 !!!" << endl;
    }
    else {
        this->a[a] = false;
    } 
}

void IntegerSet::printList(){
    for (int i=0; i<= 100 ; i++){
        if (a[i] == true) cout << i << " ";
    }
    cout << endl;
}

bool IntegerSet::isEqual(IntegerSet& a,IntegerSet& b){
    int control = 1;
    for (int i=0; i<= 100 ; i++){
        if (a.a[i] != b.a[i]) control++;
    }
    if (control == 1) return true;
    else return false;
}

IntegerSet::IntegerSet(int dizi[],int size){
    for(int i=0;i<=100;i++){
        a[i] = false;
    }
    for(int i=0;i<size;i++){
        put(dizi[i]);
    }

}