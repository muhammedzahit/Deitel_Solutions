/* 8.23 (Strings Starting with "b") Write a program that reads a series of strings and prints only
those strings beginning with the letter “b.” */
#include <stdio.h>
#include <string.h>
int main(){
    char text[100];
    gets(text);
    char character;
    int counter = 0;
    scanf("%c",&character);
    char *tokenPtr = strtok(text," ");
    while(tokenPtr != NULL){
        if (*tokenPtr == character){
            printf("%d . %s\n",counter+1,tokenPtr);
            counter++;
        }
        tokenPtr = strtok(NULL," ");
    }
    printf("Number of occurrences : %d",counter);
    return 0;
}