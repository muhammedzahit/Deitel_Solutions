#include <iostream>
#include <array>
#define COLUMN 2
#define ROW 3
using namespace std;
void printArray(array<  array< int , COLUMN > , ROW  > & numbers){
    for (auto &s : numbers){
        for (auto  &a : s){
            cout << a << " ";
        }
        cout << endl;
    }
}
int main(){
    array < array < int , COLUMN > , ROW > array = {1,2,3,4,5,6};
    printArray(array);
    return 0;
}