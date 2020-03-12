/* 8.27 (Write Your String Conversion Functions) Write your own versions of the functions strtod,strtol,strtoul */
#include <stdio.h>
#include <math.h>
int str_len(char *text);
int convertToNumber(char *character);
int stringToInteger(char *text);
int str_len_double(char *text);
double stringToDouble(char *text);
int main(){
    char text[20];
    gets(text);
    int numberInt;
    double numberDouble;
    if (str_len_double(text) == 0){
        if (*text == '-'){
            char *textPtr = text+1;
            numberInt = -1*stringToInteger(textPtr);
            printf("Integer number is %d",numberInt);
        }
        else{
            numberInt = stringToInteger(text);
            printf("Integer number is %d",numberInt);
        }
    }
    else {
        if (*text == '-'){
            char *textPtr = text+1;
            numberDouble = -1.0*stringToDouble(textPtr);
            printf("Double number is %f",numberDouble);
        }
        else {
            numberDouble = stringToDouble(text);
            printf("Double number is %f",numberDouble);
        }
    }
    return 0;
}
int str_len(char *text){
    int counter=0;
    char *textPtr = text;
    while (*textPtr != '\0'){
        textPtr++;
        counter++;
    }
    return counter;
}
int convertToNumber(char *character){
    int a = *character;
    if (a >= 48 && a <= 57 ){
        return a-48;
    }
    return -1;
}
int stringToInteger(char *text){
    int a = str_len(text);
    int number = 0;
    int b,s;
    for (s=0; s<a; s++){
        b = convertToNumber(&text[s]);
        number += (b)*(int)(pow(10,a-s-1));
    }
    return number;
}
int str_len_double(char *text){
    int counter=0,dotCounter = 0;
    char *textPtr = text;
    while (*textPtr != '.'){
        textPtr++;
        counter++;
        if (*textPtr == '.') dotCounter++;
        if (*textPtr == '\0') break;
    }
    if (dotCounter == 1){
        return counter;
    }
    else {
        return 0;
    }
}
double stringToDouble(char *text){
    int a = str_len(text);
    int c = str_len_double(text);
    double number = 0;
    int b,s;
    int d = c-1;
    for (s=0; s<a; s++){
        if (*(text+s) == '.') continue;
        b = convertToNumber(&text[s]);
        number += (b)*(pow(10,d));
        d--;
    }
    return number;
}