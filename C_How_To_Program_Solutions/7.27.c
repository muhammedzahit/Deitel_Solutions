#include <stdio.h>
int main(){
    printf("SAMSUN OS V1.0\n");
    printf("--------------------------------------------\n");
    printf("Input --> 100[number_ram_location]\n");
    printf("Output --> 200[number_ram_location]\n");
    printf("Add --> 3[number_ram_location][number_ram_location]\n");
    printf("Substract --> 4[number_ram_location][number_ram_location]\n");
    printf("Divide --> 5[number_ram_location][number_ram_location]\n");
    printf("Multiply --> 6[number_ram_location][number_ram_location]\n");
    printf("Load --> 700[number_ram_location]\n");
    printf("Same --> 8[number_ram_location][number_ram_location]\n");
    printf("Not Same --> 9[number_ram_location][number_ram_location]\n");
    printf("Exit --> 99999\n");
    printf("For same command if your numbers same output 1 if not 0\n");
    printf("For not same command if your numbers same output 0 if not 1\n");
    printf("--------------------------------------------\n");
    int ram=0,s,j;
    int memory[100] = {0};
    printf("%d ?  ",ram);
    scanf("%d",&memory[ram]);
    while (memory[ram] < 10000 || memory[ram] > 99999){
        printf("Order number must between 10000 and 99999 !!!!!\nPlease try again\n");
        printf("%d ?  ",ram);
        scanf("%d",&memory[ram]);
    }
    while (memory[ram] != 99999 && ram < 100){
        int a,b,c,d,e;
        a = memory[ram] / 10000;
        switch(a){
            case 1:
                b = memory[ram] % 100;
                printf("\n          Please enter number for ram location %d:   ",b);
                scanf("%d",&memory[b]);
                printf("          Location succesfully updated...\n");
                break;
            case 2:
                b = memory[ram] % 100;
                printf("\n          Number in ram location %d:  %d\n",b,memory[b]);
                break;
            case 3:
                b = (memory[ram]/100)%100;
                c = memory[ram]%100;
                d = memory[b] + memory[c];
                printf("\n          For load variable to ram location you must use load command !!!\n");
                break;
            case 4:
                b = (memory[ram]/100)%100;
                c = memory[ram]%100;
                d = memory[b] - memory[c];
                printf("\n          For load variable to ram location you must use load command !!!\n");
                break;
            case 5:
                b = (memory[ram]/100)%100;
                c = memory[ram]%100;
                d = memory[b] / memory[c];
                printf("\n          For load variable to ram location you must use load command !!!\n");
                break;
            case 6:
                b = (memory[ram]/100)%100;
                c = memory[ram]%100;
                d = memory[b] * memory[c];
                printf("\n          For load variable to ram location you must use load command !!!\n");
                break;
            case 7:
                b = memory[ram]%100;
                memory[b] = d;
                printf("\n          Result loaded to number in ram location %d\n",b);
                break;
            case 8:
                b = (memory[ram]/100)%100;
                c = memory[ram]%100;
                if (memory[b] == memory[c]){
                    printf("          1\n");
                }
                else{
                    printf("          0\n");
                }
                break;
            case 9:
                b = (memory[ram]/100)%100;
                c = memory[ram]%100;
                if (memory[b] == memory[c]){
                    printf("          0\n");
                }
                else{
                    printf("          1\n");
                }
        }
        ram++;
        printf("%d ?  ",ram);
        scanf("%d",&memory[ram]);
        while (memory[ram] < 10000 || memory[ram] > 99999){
            printf("Order number must between 10000 and 99999 !!!!!\nPlease try again\n");
            printf("%d ?  ",ram);
            scanf("%d",&memory[ram]);
        }
    }

    printf("Are you want to see ram trash ?(y/n)\n");
    char selection;
    scanf(" %c",&selection);
    if (selection == 'y'){
        printf("%5s","");
        for (s=0; s<10; s++){
            printf("  %5d",s);
        }
        for (s=0; s<100; s++){
            if (s % 10 == 0){
                printf("\n%5d  ",s);
                if (s == 0){
                    printf("\n   00  ");
                }
            }
            printf("%05d  ",memory[s]);
        }

    }

    printf("\n\nGoodbye..........\n");
    printf("Thank you for using Samsun OS\n");
    return 0;
}