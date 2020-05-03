#include <iostream>
#include <bitset>
using namespace std;
// 15.26 PRIME FACTORS

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
        cout << input << " = ";
        int a = 2;
        while (input > 1){
            if (!m[a]){
                a++;
                continue;
            }
            while (input % a == 0) {
                input /= a;
                if (input <= 1) cout << a;
                else cout << a << " * ";
            }
            a++;
        }
    }
    else cout << "Asal sayidir." << endl;

    return 0;
}