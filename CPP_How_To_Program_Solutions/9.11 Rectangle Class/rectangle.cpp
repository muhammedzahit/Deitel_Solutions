#include <iostream>
#include "rectangle.hpp"

using namespace std;

Rectangle::Rectangle(double Length,double Width)
    : length(Length) , width(Width) 
{
    if (width < 0 || width > 20){
        cout << "Fault : Width must be bigger than 0 and lower than 20 !!!" << endl;
        cout << "Your new width is 1.00" << endl << endl;
        width = 1.0;
    }
    if (length < 0 || length > 20){
        cout << "Fault : Length must be bigger than 0 and lower than 20 !!!" << endl;
        cout << "Your new length is 1.00" << endl << endl;
        length = 1.0;
    }
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
void Rectangle::setLength(double length){
    if (length < 0 || length > 20){
        cout << "Fault: Length must be bigger than 0 and lower than 20 !!!" << endl;
        cout << "Your new length is 1.00" << endl << endl;
        this->length = 1.0;
        return;
    }
    this->length = length;
}
void Rectangle::setWidth(double width){
    if (width < 0 || width > 20){
        cout << "Fault:Width must be bigger than 0 and lower than 20 !!!" << endl;
        cout << "Your new width is 1.00" << endl << endl;
        this->width = 1.0;
        return;
    }
    this->width = width;
}
void Rectangle::printInfo(){
    cout << "Length: " << length << endl;
    cout << "Width : " << width << endl;
    cout << "Area :" << getArea() << endl;
    cout << "Perimeter : " << getPerimeter() << endl << endl;
}