// EXAMPLE OF FRIEND FUNCTION
#include <iostream>
using namespace std;
class calisan{
friend void setMaas(calisan&,int);
friend void setName(calisan&,string);
private:
    int maas;
    string name;
public:
    calisan(int a = 0 , string b = "???") 
        : maas(a) , name(b) {}
    void print(){
        cout << "isim : " << name << endl;
        cout << "maas : " << maas << endl;
    }
};
void setMaas(calisan& x,int a){
    x.maas = a;
}
void setName(calisan& x,string a){
    x.name = a;
}
int main(){
    calisan calisan1;
    cout << "Before friend function " << endl;
    calisan1.print();
    setMaas(calisan1,2500);
    setName(calisan1,"Ahmed");
    cout << endl;
    cout << "After friend function " << endl << endl;
    calisan1.print();

    return 0;
}