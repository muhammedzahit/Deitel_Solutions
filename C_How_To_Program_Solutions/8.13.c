/*(Pig Latin) Write a program that encodes English-language phrases into pig Latin. Pig Latin is a form of coded language often used for amusement. Many variations exist in the methods used
to form pig-Latin phrases. For simplicity, use the following algorithm:
To form a pig-Latin phrase from an English-language phrase, tokenize the phrase into words
with function strtok. To translate each English word into a pig-Latin word, place the first letter of
the English word at the end of the English word and add the letters “ay.” Thus the word “jump”
becomes “umpjay,” the word “the” becomes “hetay” and the word “computer” becomes “omputercay.” Blanks between words remain as blanks. Assume the following: The English phrase consists
of words separated by blanks, there are no punctuation marks, and all words have two or more letters. Function printLatinWord should display each word. [Hint: Each time a token is found in a
call to strtok, pass the token pointer to function printLatinWord, and print the pig-Latin word.*/


#include <stdio.h>
#include <string.h>
void formPigLatin(char *tokenPtr);
int main(){

    char s[100];
    char *tokenPtr;
    printf("Enter a string:");
    scanf("%[^\n]s",s);
    tokenPtr = strtok(s," ");
    while (tokenPtr != NULL){

        formPigLatin(tokenPtr);
        tokenPtr = strtok(NULL," ");

    }
    return 0;
}
void formPigLatin(char *tokenPtr){
    char *ptr = tokenPtr;
    if (*ptr == 'a' || *ptr == 'e' || *ptr == 'o' || *ptr == 'u'){
        printf("%s",tokenPtr);
        printf("%c%c",'a','y');
        printf("\n");
    }
    else if(*(ptr+1) == 'a' || *(ptr+1) == 'e' || *(ptr+1) == 'o' || *(ptr+1) == 'u'){
        while (*(ptr+1) != '\0'){
            printf("%c",*(ptr+1));
            ptr++;
        }
        printf("%c",*tokenPtr);
        printf("%c%c%c",'w','a','y');
        printf("\n");
    }
    else{
        while (*(ptr+2) != '\0'){
            printf("%c",*(ptr+2));
            ptr++;
        }
        printf("%c",*tokenPtr);
        printf("%c",*(tokenPtr+1));
        printf("%c%c",'a','y');
        printf("\n");
    }
}