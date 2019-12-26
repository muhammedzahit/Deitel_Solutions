#include <iostream>
#include "date.h"
using namespace std;
date::date(int n_day,int n_month,int n_year)
    : day(n_day) , month(n_month) , year(n_year)
{}
void date::setDay(int n_day,int n_month,int n_year){
    day = n_day;
    month = n_month;
    year = n_year;
}
int date::getDay() const{
    return day;
}
