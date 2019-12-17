#include <iostream>
#include <vector>
using namespace std;
void printVector(vector <int> &x){
    for (int s : x){
        cout << s << " ";
    }
    cout << endl;
}
void inputVector(vector <int> &x){
    int i = 1;
    for (int &s: x){
        cout << "Enter " << i++ << " :";
        cin >> s;
    }
}

int main(){
    vector<int> a(8);
    vector<int> b(8);
    inputVector(a);
    inputVector(b);
    printVector(a);
    printVector(b);
    if (a == b){
        cout << "a = b" << endl;
    }
    else {
        cout << "a != b" << endl;
    }
    int counter = 0;
    for (int x1 : a){
        for (int x2 : b){
            if (x1 == x2 ) counter++;
        }
    }
    cout << "Number of same elements : " << counter << endl;
    return 0;
}