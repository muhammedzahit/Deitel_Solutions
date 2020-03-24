#include <iostream>
using namespace std;

class Complex{
    int real,imaginary;
public:
    friend istream& operator>>(istream&,Complex&);
    void setReal(const int& a) { real = a ;}
    void setImaginary(const int& a) {imaginary = a;}
    int getReal() {return real;}
    int getImaginary() {return imaginary;}
    friend ostream& operator<<(ostream&,Complex&);
};

istream& operator>>(istream& in,Complex& c){
    int real,image;
    char sign,i;
    in >> real;
    sign = cin.get();
    while (sign == ' ') sign = cin.get();
    if (sign == 'i'){
        c.setReal(0);
        c.setImaginary(real);
    }
    else if (sign == '\n'){
        c.setReal(real);
        c.setImaginary(0);
    }
    else{
        in >> image;
        in >> i;
        if (i != 'i') cin.setstate(ios::failbit);
        c.setReal(real);
        if (sign == '-') image *= -1;
        c.setImaginary(image);
    }
    return in;
}

ostream& operator<<(ostream& out,Complex& c){
    if (cin.fail()){
        out << "Error: Improper input";
        cout.setstate(ios::failbit);
    }
    out << c.getReal() << " + " << c.getImaginary() << "i" << endl;
}

int main(){
    Complex a;
    cin >> a;
    cout << a;
    return 0;
}
