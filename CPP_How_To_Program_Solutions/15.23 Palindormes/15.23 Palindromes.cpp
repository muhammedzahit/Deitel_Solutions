#include <iostream>
#include <vector>
using namespace std;
// 15.23 PALINDROMES

template <class T>
bool checkPalindrome(vector<T> v){
    int j = v.size() - 1;
    int i=0;
    while (i < j){
        if (v[i++] != v[j--]) return false;
    }
    return true;
}

int main(){

    vector a{1,2,3,2,1};
    cout << checkPalindrome(a);
    return 0;
}