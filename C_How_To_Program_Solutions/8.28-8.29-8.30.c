/* WRITE YOUR OWN STRLEN, STRCPY, STRCAT, STRCMP FUNCTIONS */
#include <stdio.h>
int str_len(char *text);
void str_cpy(char *text, char* text2,const int *text_size);
void str_cat (char *text,char *text2, const int *text_size);
int str_cmp (char *text,char *text2);
int main(){
    char text[10];
    char text2[20];
    puts("Enter text 1");
    gets(text);
    puts("Enter text 2");
    gets(text2);
    //int text_size = sizeof(text);

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
void str_cpy(char *text, char* text2,const int *text_size){
    // str_cpy( destination , source , text1 size )
    int s;
    if (str_len(text2)+1 > *text_size){
        printf("Operation is unrealizable !");
    }
    else{
        for (s=0; s<str_len(text2) ; s++){
            text[s] = text2[s];
        }
        text[s] = '\0';
        printf("%s\n",text);
        printf("%s",text2);
    }
}
void str_cat (char *text,char *text2, const int *text_size){
    // str_cat(destination,source , text1 size)
    if (*text_size < str_len(text)+str_len(text2)+1){
        printf("Operation is unrealizable !");
    }
    else
    {
        int j;
        int s = str_len(text);
        int a = str_len(text2);
        for (j=0; j<a; j++){
            text[s+j] = text2[j];
        }
        text[s+j] = '\0';
        printf("%s\n",text);
        printf("%s",text2);
    }
}
int str_cmp (char *text,char *text2){
    int size1 = str_len(text);
    int size2 = str_len(text2);
    int s,j,i=0;
    char holder;
    if (size1 > size2){
        s = size1;
        holder = text2[size1-1];
        text2[size1-1]='0';
    }
    else if(size2 > size1) {
        s = size2;
        holder = text[size2-1];
        text[size2-1]='0';
    }
    else {
        s = size1;
    }
    int number1 = 0,number2 = 0;
    for (j=0; j<s; j++){

        number1 = text[j];
        number2 = text2[j];
        if (number1 > number2){
            i = 1;
            break;
        }
        if (number1 < number2){
            i = -1;
            break;
        }
    }
    if (size1 > size2){
        text2[size1-1]='\0';
    }
    else {
        text[size2-1]='\0';
    }
    return i;
}