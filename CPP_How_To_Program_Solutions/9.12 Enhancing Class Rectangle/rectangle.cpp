#include <iostream>
#include "rectangle.hpp"

using namespace std;

void control(int* x){
    if (*x < 0 || *x > 20){
        cout << "Fault: Coordinations must be bigger than 0 and lower than 21 !!!" << endl;
        cout << "Your new cordination is 1.00" << endl << endl;
        *x = 1.0;
    }
}

Rectangle::Rectangle(int X1,int Y1,int X2,int Y2,int X3,int Y3,int X4,int Y4)
    : x1(X1) , y1(Y1) , x2(X2) , y2(Y2) , x3(X3) , y3(Y3) , x4(X4) , y4(Y4)
{
    control(&x1);control(&y1);control(&x2);control(&y2);control(&x3);control(&y3);control(&x4);control(&y4);
    if (!controlRectangle()) cout << "Coordinates doesn't generate a rectangle!!" << endl;
    else{
        length = y2-y1;
        width = x3-x1;
    }
    if (controlSquare()) cout << "Coordinates generate a Square" << endl;
}

double Rectangle::getArea(){
    return length*width;
}
double Rectangle::getPerimeter(){
    return 2*(length+width);
}
double Rectangle::getLength(){
    return length;
}
double Rectangle::getWidth(){
    return width;
}
void Rectangle::printInfo(){
    cout << "Length: " << length << endl;
    cout << "Width : " << width << endl;
    cout << "Area :" << getArea() << endl;
    cout << "Perimeter : " << getPerimeter() << endl << endl;
}

int Rectangle::controlRectangle(){
    if (x3-x1 != x4-x2 || y2-y1 != y3-y4){
        return 0;
    }
    return 1;
}

int Rectangle::controlSquare(){
    if (length != width) return 0;
    return 1;
}