#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int getSize(const string& str){
    int size = 1;
    while(true){
        if(str[size] == '\0') break;
        size++;
    }
    return size;
}

int main(){

    string a;
    cout << "Enter a string -> ";
    getline(cin,a);
    cout << setw(getSize(a)*2) << a << endl;
    return 0;
}
