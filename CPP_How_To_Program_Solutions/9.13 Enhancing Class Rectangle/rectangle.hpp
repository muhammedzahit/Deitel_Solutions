#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle{
public:
    Rectangle(int=1,int=1,int=1,int=1,int=1,int=1,int=1,int=1);
    double getArea();
    double getPerimeter();
    double getLength();
    double getWidth();
    void printInfo();
    int controlRectangle(); // 1:Rectangle 0:Not
    int controlSquare(); //1:Square 0:Not
    void drawRect();
private:
    double length,width;
    int x1,x2,x3,x4;

    int y1,y2,y3,y4;
};

#endif
