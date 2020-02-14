#include "hugeint.h"
#include <cctype>
#include <sstream>
using namespace std;
h_int::h_int(const std::string &a) {
    int size = a.size();
    if (size > 30){
        throw invalid_argument("You must enter under 31 digit number !!!");
    }
    for (short &item : integer){
        item = 0;
    }
    int k = 0;
    for (int i=size; i>0; i-- , k++){
        if (!isdigit(a[k])) throw invalid_argument("You must enter an integer number!");
        integer[digits-i] = a[k] - '0';
    }
}

std::ostream &operator<<(std::ostream &output, h_int &a) {
    for (short &item : a.integer){
        output << item;
    }
    output << endl;
    return output;
}

h_int h_int::operator+(h_int &right) const {
    if (integer[0] + right.integer[0] > 9){
        throw invalid_argument("The addition result is bigger than 30 digits!");
    }
    h_int final("0");
    for (short &item : final.integer){
        item = 0;
    }
    int carry = 0;
    for (int i=digits-1; i>=0; i--){
        final.integer[i] = integer[i] + right.integer[i] + carry;
        if (final.integer[i] > 9){
            carry = 1;
            final.integer[i] %= 10;
        }
        else carry = 0;
    }
    return final;
}

h_int h_int::operator*(h_int &right) const {
    h_int final("0");

    int carry = 0;
    for (int j=29, k=0; j>=0; j--, k++){
        h_int a("0");
        short temp = integer[j];
        for (int i=29 ; i>=0; i--){
            if (i-k < 0) break;
            a.integer[i-k] = (temp * right.integer[i]) + carry;
            if (a.integer[i-k] > 9){
                carry = a.integer[i-k] / 10;
                a.integer[i-k] %= 10;
            }
            else carry = 0;
        }
        final = final + a;
    }
    return final;
}
h_int h_int::operator/(h_int &right) const {

    double a = 0.0;
    double b = 0.0;
    short point = 0;
    for (int i=0; i<30; i++){
        if (integer[i] == 0) continue;
        else {
            for (int j=i; j<30; j++){
                a += integer[j];
                a *= 10;
            }
            a /= 10;
            break;
        }
    }
    for (int i=0; i<30; i++){
        if (right.integer[i] == 0) continue;
        else {
            for (int j=i; j<30; j++){
                b += right.integer[j];
                b *= 10;
            }
            b /= 10;
            break;
        }
    }
    a = a / b;
    string s = to_string(a);
    stringstream token(s);
    getline(token,s,'.');
    h_int final(s);
    return final;
}