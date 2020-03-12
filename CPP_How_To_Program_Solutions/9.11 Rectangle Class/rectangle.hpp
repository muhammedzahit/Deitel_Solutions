#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle{
public:
    Rectangle(double=1.0,double=1.0);
    double getArea();
    double getPerimeter();
    double getLength();
    double getWidth();
    void setLength(double);
    void setWidth(double);
    void printInfo();
private:
    double length,width;
};

#endif
