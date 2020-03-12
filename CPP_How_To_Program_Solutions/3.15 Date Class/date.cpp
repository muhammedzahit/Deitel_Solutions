#include "date.h"
#include <iostream>
using namespace std;
void date::controlDay() {
    if (month == 2){
        if ((year % 4 == 0) && ((year % 400 == 0) || (year % 100 != 0))  ){
            if (day > 29 && day > 0){
                cout << "Fault : In leap years in February day must be under 30 !" << endl;
                day = 0;
            }
        }
        else {
            if (day > 28 && day > 0){
                cout << "Fault : In not leap years in February day must be under 29 !" << endl;
                day = 0;
            }
        }
    }
    else {
        if (month % 2 == 1){
            if (day > 31 && day > 0){
                cout << "Fault : In this month day must be under 31 !" << endl;
                day = 0;
            }
            else if (day > 30 && day > 0) {
                cout << "Fault : In this month day must be under 30 !" << endl;
                day = 0;
            }
        }
    }
}
date::date(int day, int month, int year)
    :day(day),month(month),year(year)
{
    if (!(month > 0 && month < 13)) {
        cout << "Fault : Month must be between 0 and 12 ! " << endl;
        month = 1;
    }
    if (year < 0){
        cout << "Fault : Year must be upper than 0 ! " << endl;
        year = 2000;
    }
    controlDay();
}
void date::setDay(int number) {
    day = number;
    controlDay();
}
int date::getDay() {
    return day;
}
void date::setMonth(int number) {
    month = number;
    if (month < 0 ||month > 12){
        cout << "Fault : Month must be between 0 and 12 ! " << endl;
        month = 1;
    }
}
int date::getMonth() {
    return month;
}
void date::setYear(int number) {
    year = number;
    if (year < 0){
        cout << "Fault : Year must be upper than 0 ! " << endl;
        year = 2000;
    }
}
int date::getYear() {
    return year;
}
void date::displayDate() {
    cout << day << "/" << month << "/" << year << endl;
}