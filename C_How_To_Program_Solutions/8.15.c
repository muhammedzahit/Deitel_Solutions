/*8.15 (Displaying a Sentence with Its Words Reversed) Write a program that inputs a line of text,
tokenizes the line with function strtok and outputs the tokens in reverse order.*/
#include <stdio.h>
#include <string.h>
void reverse(char *ptr);
int main(){
    char text[100];
    gets(text);
    char *tokenPtr = strtok(text," ");
    reverse(tokenPtr);
    return 0;
}
void reverse(char *ptr){
    char *holder = ptr;
    if (ptr == NULL){
        return;
    }
    ptr = strtok(NULL," ");
    reverse(ptr);
    printf("%s\n",holder);
}