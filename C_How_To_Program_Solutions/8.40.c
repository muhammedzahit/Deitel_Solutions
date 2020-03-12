/*
(A Metric Conversion Program) Write a program that will assist the user with metric conversions. Your program should allow the user to specify the names of the units as strings (i.e., centimeters, liters, grams, and so on for the metric system and inches, quarts, pounds, and so on for the
English system) and should respond to simple questions such as
"How many inches are in 2 meters?"
"How many liters are in 10 quarts?"
Your program should recognize invalid conversions. For example, the question
"How many feet in 5 kilograms?"
is not meaningful, because "feet" are units of length while "kilograms" are units of mass.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void conversions (char *holder1,char *holder2,double *amount);
int main(){
    printf("Enter your question (for example how many inches 2 meters ?)\n");
    char question[100];
    gets(question);
    char *tokenPtr = strtok(question," ");
    char *holder1 , *holder2 ;
    int s;
    double amount;
    for (s=0; s<2; s++){
        tokenPtr = strtok(NULL, " ");
    }
    holder1 = tokenPtr;
    tokenPtr = strtok(NULL, " ");
    amount = atof(tokenPtr);
    tokenPtr = strtok(NULL, " ");
    holder2 = tokenPtr;
    conversions(holder1,holder2,&amount);
    return 0;
}
void conversions (char *holder1,char *holder2,double *amount) {
    char EU[7][10] = {"miles","feet","inches","pounds","ounces","gallons","celsius"};
    char SI[7][12] = {"kilometers","meters","centimeters","grams","liters","kelvin","kilograms"};
    if (strcmp(holder1,EU[0]) == 0){
        if (strcmp(holder2,SI[0]) == 0){
            printf("\n%f miles",(0.621 * (*amount)));
        }
        else if (strcmp(holder2,SI[1]) == 0){
            printf("\n%f miles",(0.000621 * (*amount)));
        }
        else if (strcmp(holder2,SI[2]) == 0){
            printf("\n%f miles",(0.00000621 * (*amount)));
        }
        else {
            printf("\nConversion is wrong !");
        }
    }
    if (strcmp(holder1,EU[1]) == 0){
        if (strcmp(holder2,SI[0]) == 0){
            printf("\n%.9f feet",(3280.8399 * (*amount)));
        }
        else if (strcmp(holder2,SI[1]) == 0){
            printf("\n%.9f feet",(3.2808399 * (*amount)));
        }
        else if (strcmp(holder2,SI[2]) == 0){
            printf("\n%.9f feet",(0.032808399 * (*amount)));
        }
        else {
            printf("\nConversion is wrong !");
        }
    }
    if (strcmp(holder1,EU[2]) == 0){
        if (strcmp(holder2,SI[0]) == 0){
            printf("\n%.9f inches",(39370.0787 * (*amount)));
        }
        else if (strcmp(holder2,SI[1]) == 0){
            printf("\n%.9f inches",(39.3700787 * (*amount)));
        }
        else if (strcmp(holder2,SI[2]) == 0){
            printf("\n%.9f inches",(0.393700787 * (*amount)));
        }
        else {
            printf("\nConversion is wrong !");
        }
    }
    if (strcmp(holder1,EU[3]) == 0){
        if (strcmp(holder2,SI[3]) == 0){
            printf("\n%.9f pounds",(0.00220462262 * (*amount)));
        }
        if (strcmp(holder2,SI[6]) == 0){
            printf("\n%.9f pounds",(2.20462262 * (*amount)));
        }
        else {
            printf("\nConversion is wrong !");
        }
    }
    if (strcmp(holder1,EU[4]) == 0){
        if (strcmp(holder2,SI[3]) == 0){
            printf("\n%.9f ounces",(0.0352739619 * (*amount)));
        }
        if (strcmp(holder2,SI[6]) == 0){
            printf("\n%.9f ounces",(35.2739619 * (*amount)));
        }
        else {
            printf("\nConversion is wrong !");
        }
    }
    if (strcmp(holder1,EU[5]) == 0){
        if (strcmp(holder2,SI[4]) == 0){
            printf("\n%.9f gallons",( 0.264172052 * (*amount)) );
        }
        else {
            printf("\nConversion is wrong !");
        }
    }
    if (strcmp(holder1,EU[6]) == 0){
        if (strcmp(holder2,SI[5]) == 0){
            printf("\n%.2f celcius",( *amount + -273.15 ));
        }
        else {
            printf("\nConversion is wrong !");
        }
    }
    if (strcmp(holder1,SI[0]) == 0){
        if (strcmp(holder2,EU[0]) == 0){
            printf("\n%.9f kilometers",(1.609344 * (*amount)));
        }
        else if (strcmp(holder2,EU[1]) == 0){
            printf("\n%.9f kilometers",(0.0003048 * (*amount)));
        }
        else if (strcmp(holder2,EU[2]) == 0){
            printf("\n%.9f kilometers",(0.0000254 * (*amount)));
        }
        else {
            printf("\nConversion is wrong !");
        }
    }
    if (strcmp(holder1,SI[1]) == 0){
        if (strcmp(holder2,EU[0]) == 0){
            printf("\n%.9f meters",(1609.344 * (*amount)));
        }
        else if (strcmp(holder2,EU[1]) == 0){
            printf("\n%.9f meters",(0.3048 * (*amount)));
        }
        else if (strcmp(holder2,EU[2]) == 0){
            printf("\n%.9f meters",(0.0254 * (*amount)));
        }
        else {
            printf("\nConversion is wrong !");
        }
    }
    if (strcmp(holder1,SI[2]) == 0){
        if (strcmp(holder2,EU[0]) == 0){
            printf("\n%.9f centimeters",(160934.4 * (*amount)));
        }
        else if (strcmp(holder2,EU[1]) == 0){
            printf("\n%.9f centimeters",(30.48 * (*amount)));
        }
        else if (strcmp(holder2,EU[2]) == 0){
            printf("\n%.9f centimeters",(2.54 * (*amount)));
        }
        else {
            printf("\nConversion is wrong !");
        }
    }
    if (strcmp(holder1,SI[3]) == 0){
        if (strcmp(holder2,EU[3]) == 0){
            printf("\n%.9f grams",(453.59237 * (*amount)));
        }
        else if (strcmp(holder2,EU[4]) == 0){
            printf("\n%.9f grams",(28.3495231 * (*amount)));
        }
        else {
            printf("\nConversion is wrong !");
        }
    }
    if (strcmp(holder1,SI[4]) == 0){
        if (strcmp(holder2,EU[5]) == 0){
            printf("\n%.9f liters",( 3.78541178 * (*amount)) );
        }
        else {
            printf("\nConversion is wrong !");
        }
    }
    if (strcmp(holder1,SI[5]) == 0){
        if (strcmp(holder2,EU[6]) == 0){
            printf("\n%.2f kelvin",( 273.15 + (*amount)) );
        }
        else {
            printf("\nConversion is wrong !");
        }
    }
    if (strcmp(holder1,SI[6]) == 0){
        if (strcmp(holder2,EU[3]) == 0){
            printf("\n%.9f kilograms",(0.45359237 * (*amount)));
        }
        else if (strcmp(holder2,EU[4]) == 0){
            printf("\n%.9f kilograms",(0.0283495231 * (*amount)));
        }
        else {
            printf("\nConversion is wrong !");
        }
    }
}