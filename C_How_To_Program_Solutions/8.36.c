/* (Printing Dates in Various Formats)
Dates are commonly printed in several different formats in business correspondence. Two of the more common formats are
07/21/2003 and July 21, 2003
Write a program that reads a date in the first format and prints it in the second format. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char date[100];
    char months[12][10] = {"Ocak", "Şubat", "Mart", "Nisan", "Mayıs", "Haziran", "Temmuz", "Ağustos", "Eylül", "Ekim",
                           "Kasım", "Aralık"};
    printf("Enter a date (m/d/year) :  ");
    scanf("%[^\n]s", date);
    int dayNo, yearNo, monthNo;
    char *tokenPtr = strtok(date, "/");
    monthNo = atoi(tokenPtr);
    tokenPtr = strtok(NULL, "/");
    dayNo = atoi(tokenPtr);
    tokenPtr = strtok(NULL, "/");
    yearNo = atoi(tokenPtr);
    printf("%d %s,%d", dayNo, months[monthNo - 1], yearNo);
    return 0;
}