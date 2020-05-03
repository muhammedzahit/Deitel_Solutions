#include <iostream>
#include <bitset>
using namespace std;
// 15.25 SEA OF ERATOSTHENES

int main(){

    bitset<1023> m;
    m.flip();
    for (int i=2; i<1023; i++){
        if (!m[i]) continue;
        else {
            for (int a= 2*i ; a <= 1023 ; a += i) m[a] = false;
        }
    }
    int input;
    cin >> input;
    if (!m[input]){
        cout << "Asal Sayi degildir" << endl;
        cout << "Asal bolenler : ";
        int a = 2;
        while (input > 1){
            if (!m[a]){
                a++;
                continue;
            }
            if (input % a == 0) cout << a << " ";
            while (input % a == 0) input /= a;
            a++;
        }
    }
    else cout << "Asal sayidir." << endl;

    return 0;
}