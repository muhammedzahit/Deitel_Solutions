/* 8.24 (Strings Ending with "ed") Write a program that reads a series of strings and prints only
those strings that end with the letters “ed.” */
#include <stdio.h>
#include <string.h>
void control_token(char *tokenPtr,char *string);
int main(){
    char text[100];
    gets(text);
    char string[3];
    gets(string);
    char *tokenPtr = strtok(text," ");
    while (tokenPtr != NULL){
        control_token(tokenPtr,string);
        tokenPtr = strtok(NULL, " ");
    }
    return 0;
}
void control_token(char *tokenPtr,char *string){
    char *holderPtr = tokenPtr;
    while (*holderPtr != '\0'){
        holderPtr++;
    }
    holderPtr--;
    if (string[1] == *holderPtr && string[0] == *(holderPtr-1)){
        printf("%s\n",tokenPtr);
    }
}