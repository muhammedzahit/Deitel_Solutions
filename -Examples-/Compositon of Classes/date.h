#ifndef DATE_H
#define DATE_H
class date{
public:
    date(int,int,int);
    void setDay(int,int,int);
    int getDay() const;
private:
    int day;
    int month;
    int year;
};

#endif

