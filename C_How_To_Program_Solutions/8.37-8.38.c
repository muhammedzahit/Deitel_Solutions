/* (Check Protection) */
#include <stdio.h>
void printHandwriting (int *number) ;
void printCheck(int *c,int *b,int *a);
int main(){
    printf("Enter check amount :");
    int amount;
    scanf("%d",&amount);
    int a,b,c;
    a = amount%1000;
    amount /= 1000;
    b = amount%1000;
    amount /= 1000;
    c = amount%1000;
    printf("%03d.%03d.%03d $\n",c,b,a);
    printCheck(&c,&b,&a);
    return 0;
}
void printHandwriting (int *number) {
    char birlik[9][10] = {"bir","iki","uc","dort","bes","alti","yedi","sekiz","dokuz"};
    char onluk[9][10] = {"on","yirmi","otuz","kırk","elli","altmis","yetmis","seksen","doksan"};
    int i = *number / 100;
    if (i > 0){
        if ( i == 1) printf("yuz");
        else {
            printf("%s yuz ",birlik[i-1]);
        }
    }
    int s = (*number%100)/10;
    if (s>0){
        printf(" %s",onluk[s-1]);
    }
    int j = (*number%10);
    if (j > 0){
        printf(" %s",birlik[j-1]);
    }
}
void printCheck(int *c,int *b,int *a){
    printHandwriting(c);
    printf(" milyon,");
    printHandwriting(b);
    printf(" bin,");
    printHandwriting(c);
}