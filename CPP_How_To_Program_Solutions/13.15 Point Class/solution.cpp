#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
using namespace std;

class Point{
    int x;
    int y;
public:
    int getX() const {return x;}
    int getY() const{return y;}
    void setY(int a){ y = a ;}
    void setX(int a){ x = a ;}
    friend ostream& operator <<(ostream&,Point&);
    friend istream& operator >>(istream&,Point&);
};

ostream& operator <<(ostream& out,Point& x){
    if (cin.fail()){
        cout << endl <<  "Fault : Improper input!!!" << endl;
        cout.setstate(ios::failbit);
    }
    cout << "X location -> " << x.getX() << endl;
    cout << "Y location -> " << x.getY() << endl;
}

istream& operator >>(istream& in,Point& x){
    int a;
    cout << "Enter x location" << endl;
    cin >> a;
    x.setX(a);
    cout << "Enter y location" << endl;
    cin >> a;
    x.setY(a);
}

int main(){

    Point p1;
    cin >> p1;
    cout << p1;
    cin >> p1;
}
