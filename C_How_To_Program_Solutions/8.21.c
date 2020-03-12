#include <string.h>
#include <stdio.h>
int main(){
    char texts[10][30];
    int i,s;
    for (i=0; i<10; i++){
        scanf("%s",texts[i]);
    }
    char holder[30];
    for (i=0; i<9; i++){
        for (s=0; s<9; s++){
            if (strcmp(texts[s],texts[s+1]) > 0){
                strcpy(holder,texts[s+1]);
                strcpy(texts[s+1],texts[s]);
                strcpy(texts[s],holder);
            }
        }
    }
    for (i=0; i<10; i++){
        printf("%s\n",texts[i]);
    }
    return 0;
}