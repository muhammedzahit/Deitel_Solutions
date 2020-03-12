#include <iostream>
#include "integer.hpp"
using namespace std;
int main(){
    int a[]={1,2,3,4,20};
    int size = sizeof(a)/sizeof(a[0]);
    IntegerSet number_list_1;
    IntegerSet number_list_2;
    number_list_1.put(1);
    number_list_2.put(2);
    number_list_2.put(1);
    IntegerSet union_number_list = number_list_1.UnionofSets(number_list_1,number_list_2);
    IntegerSet intersection = number_list_1.IntersectionOfSets(number_list_1,number_list_2);
    union_number_list.printList();
    intersection.printList();
    if (number_list_1.isEqual(union_number_list,intersection) == true) cout << "Equal" << endl;
    else cout << "Not Equal" << endl;
    IntegerSet new_list(a,size);
    new_list.printList();
    new_list.deleteNum(20);
    new_list.printList();

    return 0;
}