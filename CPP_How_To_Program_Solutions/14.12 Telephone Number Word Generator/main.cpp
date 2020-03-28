#include <iostream>
#include <string>
#include <fstream>
using namespace std;
char letters[8][4] = {{'A','B','C',' '},{'D','E','F',' '},{'G','H','I',' '},{'J','K','L',' '},
        {'M','N','O',' '},{'P','Q','R','S'},{'T','U','V',' '},{'W','X','Y','Z'}
};

void print(int i,int a[],string name){
    if (i <= 5) {
        for (int j = 0; j < 4; j++) {
            if ((a[i] != 7 && j == 3) || (a[i] != 9 && j == 3)) continue;
            name[i] = letters[a[i]-2][j];
            print(i+1, a, name);
        }
    }
    else if (i == 6){
        for (int j=0; j<4 ; j++){
            if ((a[i] != 7 && j == 3) || (a[i] != 9 && j == 3)) continue;
            name[i] = letters[a[i]-2][j];
            ofstream file("names.txt",ios::out|ios::app);
            file << name << endl;
        }
    }
}

int main(){

    string b;
    int a[7];
    getline(cin,b);
    for (int i=0; i<3; i++){
        a[i] = b[i] - '0';
    }
    for (int i=3; i<7; i++){
        a[i] = b[i+1] - '0';
    }
    string name = "0000000"; // öylesine bir şeyler verdim burada
    print(0,a,name);
    return 0;
}