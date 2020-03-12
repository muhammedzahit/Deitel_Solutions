#include <stdio.h>
int main(){
    char text[100];
    int counter[26] = {0};
    gets(text);
    int i=0,s;
    while (text[i] != '\0'){
        if (text[i] >= 'a' && text[i] <= 'z'){
            s = text[i] - 'a';
            counter[s]++;
        }
        i++;
    }
    for (s=0; s<26; s++){
        printf("Occurrences of %c is %d\n",'a'+ s,counter[s]);
    }
    return 0;
}