#include <iostream>
#include <string>
using namespace std;

int main(){

    string a = "ahmed=>mehmed=>ali";
    string b = "=>"; // bolunecek string
    string c; // bolunen deger atanacak
    int end = a.find(b); // bolunecek stringin bulundugu pozisyondan bir oncesine gec
    int start = 0; // 0 pozisyonuna git
    c = a.substr(start,end-start);
    cout << c << endl;
    while (end != std::string::npos /*npos fonksiyonu dizinin sonunu bulur */){
        start = end + b.length() ; // start ın yeni konumunu gir
        end = a.find(b,start); // end in yeni konumunu gir
        c = a.substr(start,end-start); // fonksiyonu kes
        cout << c << endl; // bolunmus hali yazdir
    }
}