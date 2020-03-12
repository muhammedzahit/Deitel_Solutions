/*8.16 (Searching for Substrings) Write a program that inputs a line of text and a search string
from the keyboard. Using function strstr, locate the first occurrence of the search string in the line
of text, and assign the location to variable searchPtr of type char *. If the search string is found,
print the remainder of the line of text beginning with the search string. Then, use strstr again to
locate the next occurrence of the search string in the line of text. If a second occurrence is found,
print the remainder of the line of text beginning with the second occurrence. [Hint: The second call
to strstr should contain searchPtr + 1 as its first argument.]*/
#include <stdio.h>
#include <string.h>
int searchString(char *searchPtr,char *string);
int i=0;
int main(){

    char text[100];
    printf("Enter a text line: ");
    gets(text);
    printf("Enter a string:  ");
    char string[50];
    gets(string);
    char *searchPtr = strstr(text,string);
    int a=searchString(searchPtr,string);
    printf("\nNumber of Occurrences: %d",a);
    return 0;
}
int searchString(char *searchPtr,char *string){
    char *holder;
    while (searchPtr != NULL){
        i++;
        holder = searchPtr;
        searchPtr = strstr(searchPtr+1,string);
        printf("%s\n",holder);
    }
    return i;

}