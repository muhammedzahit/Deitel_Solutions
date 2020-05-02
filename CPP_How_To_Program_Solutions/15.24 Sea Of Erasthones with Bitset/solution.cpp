#include <iostream>
#include <bitset>
using namespace std;
// 15.24 SEA OF ERATOSTHENES WITH BITSET

int main(){

    bitset<1023> m;
    m.flip();
    for (int i=2; i<1023; i++){
        if (!m[i]) continue;
        else {
            for (int a= 2*i ; a <= 1023 ; a += i) m[a] = false;
        }
    }
    for (int i=2; i<1023; i++){
        if (m[i]) cout << i << endl;
    }

    return 0;
}