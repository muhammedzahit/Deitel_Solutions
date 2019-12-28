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

int mutlak(int x){
    if (x < 0){
        return -x;
    }
    return x;
}

Rectangle::Rectangle(int X1,int Y1,int X2,int Y2,int X3,int Y3,int X4,int Y4)
    : x1(X1) , y1(Y1) , x2(X2) , y2(Y2) , x3(X3) , y3(Y3) , x4(X4) , y4(Y4)
{
    control(&x1);control(&y1);control(&x2);control(&y2);control(&x3);control(&y3);control(&x4);control(&y4);
    if (!controlRectangle()) cout << "Coordinates doesn't generate a rectangle!!" << endl;
    else{
        if (y2 == y1){
            length = mutlak(y2-y3);
        }
        else{
            length = mutlak(y2-y1);
        }
        if (x3==x1){
            width = mutlak(x3-x2);
        }
        else{
            width = mutlak(x3-x1);
        }
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
    if (mutlak(x1-x3) != mutlak(x4-x2) || mutlak(y2-y1) != mutlak(y4-y3)){
        return 0;
    }
    return 1;
}

int Rectangle::controlSquare(){
    if (length != width) return 0;
    return 1;
}

void swap(int* x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Rectangle::drawRect(){
    int x,y,temp;
    if (x1 == x3) swap(&x3,&x2);
    if (y1 == y3) swap(&y2,&y3);
    if (x3 - x1 < 0){
        temp = x1;
        x1 = x3;
        x3 = temp;
    }
    if (y3 - y1 < 0){
        temp = y1;
        y1 = y3;
        y3 = temp;
    }
    for (x = 1 ; x <=20 ; x++){
        for (y=1 ; y<=20; y++){
            if ((y ==y1 || y == y3) && (x <= x3 && x >= x1)){
                cout << "*";
            }
            else if ((y <= y3 && y>= y1) && (x == x1 || x == x3) ){
                cout << "*";
            }
            else {
                cout << " ";
            }
            
        }
        cout << endl;
    }
}