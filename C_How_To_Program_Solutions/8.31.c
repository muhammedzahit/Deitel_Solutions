/* (Text Analysis)

   Write a program that reads several lines of text and prints a table indicating the number
   of occurrences of each letter of the alphabet in the text

   Write a program that reads several lines of text and prints a table indicating the number
   of one-letter words, two-letter words, three-letter words, and so on, appearing in the
   text.

   Write a program that reads several lines of text and prints a table indicating the number
   of occurrences of each different word in the text. The first version of your program
   should include the words in the table in the same order in which they appear in the text.
   A  more interesting (and useful) printout should then be attempted in which the words
   are sorted alphabetically */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void read_characters(char *text,int *characterArray);
void print_character_diagram(int *characterArray);
void read_words(char *text, int *lengthWords);
void print_word_length_diagram(int *length);
void repeat_number_words(char *text,int *size,char *ptr,int *ptrNum);
int main(){
    int characterArray[26] = {0};
    int lengthWords[20] = {0};
    int size = 0;
    char *ptr = malloc(size);
    int *ptrNum = malloc(size);
    char text[100];
    int a,flag = 0;
    while (flag == 0){
        printf("1-Read character diagram\n");
        printf("2-Read length of words diagram\n");
        printf("3-Read occurrences of words diagram\n");
        printf("4-Quit\n");
        printf("Selection: ");
        scanf("%d",&a);
        switch(a){
            case 1:
                printf("Enter text line: ");
                scanf(" %[^\n]s",text);
                read_characters(text,characterArray);
                print_character_diagram(characterArray);
                break;
            case 2:
                printf("Enter text line: ");
                scanf(" %[^\n]s",text);
                read_words(text,lengthWords);
                print_word_length_diagram(lengthWords);
                break;
            case 3:
                printf("Enter text line: ");
                scanf(" %[^\n]s",text);
                repeat_number_words(text,&size,ptr,ptrNum);
                break;
            case 4:
                flag = 1;
                break;
        }
    }
    free(ptr);
    free(ptrNum);
    return 0;
}
void read_characters(char *text,int *characterArray){
    int a;
    while (*text != '\0'){
        a = *text;
        if (a >= 97 && a <= 122){
            characterArray[a-97]++;
        }
        if (a >= 65 && a <= 90){
            characterArray[a-65]++;
        }
        text++;
    }
}
void print_character_diagram(int *characterArray){
    int s;
    for (s=0; s<26; s++){
        printf("occurrences of %c is %d\n",97+s,characterArray[s]);
    }
}
void read_words(char *text, int *lengthWords){
    int a;
    char *tokenPtr = strtok(text," ");
    printf("%s",tokenPtr);
    while (tokenPtr != NULL){
        a = (int)strlen(tokenPtr)-1;
        lengthWords[a]++;
        tokenPtr = strtok(NULL," ");
    }
    printf("%s",tokenPtr);
}
void print_word_length_diagram(int *length){
    int s;
    for (s=0; s<20; s++){
        printf("Number of words length %d : %d\n",s+1,length[s]);
    }
}
void repeat_number_words(char *text,int *size,char *ptr,int *ptrNum){
    char *tokenPtr = strtok(text," ");
    int s,j,flag = 0;
    char *holderPtr;
    while (tokenPtr != NULL){
        flag = 0;
        j=0;
        for (s=0; s<(*size); s++){
            if (strcmp(tokenPtr,ptr+(10*s)) == 0){
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            (*size)++;
            ptr = realloc(ptr,(*size)*10);
            ptrNum = realloc(ptrNum,(*size)*4);
            holderPtr = tokenPtr;
            while (*holderPtr != '\0'){
                *(ptr+((*size)*10)+j-10) = *holderPtr;
                j++;
                holderPtr++;
            }
            *(ptr+((*size)*10)+j-10) = '\0';
            *(ptrNum+(*size)-1) = 1;
            tokenPtr = strtok(NULL," ");
        }
        if (flag == 1){
            tokenPtr = strtok(NULL," ");
            *(ptrNum+s) += 1;

        }
    }
    int i;
    for (i=0; i<(*size); i++){
        printf("\n%s :%d\n",ptr+(10*i),*(ptrNum+i));
    }
}