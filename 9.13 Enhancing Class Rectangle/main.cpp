#include <iostream>
#include "rectangle.hpp"
using namespace std;

Rectangle generateRectangle(){
    int x1,x2,x3,x4,y1,y2,y3,y4;
    cout << "Enter coordinate 1(x,y):" << endl;
    cin >> x1 >> y1;
    cout << "Enter coordinate 2(x,y):" << endl;
    cin >> x2 >> y2;
    cout << "Enter coordinate 3(x,y):" << endl;
    cin >> x3 >> y3;
    cout << "Enter coordinate 4(x,y):" << endl;
    cin >> x4 >> y4;
    Rectangle newRect(x1,y1,x2,y2,x3,y3,x4,y4);
    return newRect;
}

int main(){

    Rectangle rectangle1 = generateRectangle();
    rectangle1.drawRect();
    return 0;
}