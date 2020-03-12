#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int printFloor(int floor[][8],int x,int y);
void moveKnight(int floor[][8],int *x,int *y);
int main(){
    srand(time(NULL));
    int floor[8][8]={0};
    int x = rand()%8;
    int y = rand()%8;
    floor[x][y] = 1;
    printf("KNIGHT CHESS PROBLEM\n");
    int a = 1,cntr=0,s;
    int selection;
    while (a == 1){
        printf("1-Print Floor\n");
        printf("2-Move Knight\n");
        printf("9-End program\n");
        printf("Selection: ");
        scanf("%d",&selection);
        switch(selection){
            case 1:
                s = printFloor(floor,x,y);
                break;
            case 2:
                moveKnight(floor,&x,&y);
                s = printFloor(floor,x,y);
                break;
            case 9:
                a = 0;
                break;
        }
        cntr++;
        if (cntr == 63){
            printf("You solved problem genius.");
            a = 0;
        }
        else if (s == 0){
            a = 0;
            printf("Sorry , try again ...");
        }
    }
    return 0;
}
int printFloor(int floor[][8],int x,int y){
    int i,j,cntr=0;
    printf("\n\nFLOOR:\n");
    for (i=0; i<8; i++){
        for (j=0; j<8; j++){
            if (i==x && j == y ){
                printf("%3s","K");
            }
            else if (i == x-1 &&  j==y+2 && floor[i][j] <= 0){
                printf("%3s","A");
                cntr++;
            }
            else if (i == x-2 && j== y+1 && floor[i][j] <= 0){
                printf("%3s","B");
                cntr++;
            }
            else if (i == x-2 && j== y-1 && floor[i][j] <= 0){
                printf("%3s","C");
                cntr++;
            }
            else if (i == x-1 && j== y-2 && floor[i][j] <= 0){
                printf("%3s","D");
                cntr++;
            }
            else if (i == x+1 && j== y-2 && floor[i][j] <= 0){
                printf("%3s","E");
                cntr++;
            }
            else if (i == x+2 && j== y-1 && floor[i][j] <= 0){
                printf("%3s","F");
                cntr++;
            }
            else if (i == x+2 && j== y+1 && floor[i][j] <= 0){
                printf("%3s","G");
                cntr++;
            }
            else if (i == x+1 && j== y+2 && floor[i][j] <= 0){
                printf("%3s","H");
                cntr++;
            }
            else if (floor[i][j] != 0){
                printf("%3d",floor[i][j]);

            }
            else {
                printf("%3d",0);

            }

        }
        printf("\n");
    }
    printf("\n\n");
    return cntr;
}
void moveKnight(int floor[][8],int *x,int *y){
    printf("Which letter do you want to go ?  ");
    char c;
    static int number=1;
    scanf(" %c",&c);
    switch(c){
        case 'A':
            floor[*x][*y] = number;
            number++;
            *x -= 1;
            *y += 2;
            break;
        case 'B':
            floor[*x][*y] = number;
            number++;
            *x -= 2;
            *y += 1;
            break;
        case 'C':
            floor[*x][*y] = number;
            number++;
            *x -= 2;
            *y -= 1;
            break;
        case 'D':
            floor[*x][*y] = number;
            number++;
            *x -= 1;
            *y -= 2;
            break;
        case 'E':
            floor[*x][*y] = number;
            number++;
            *x += 1;
            *y -= 2;
            break;
        case 'F':
            floor[*x][*y] = number;
            number++;
            *x += 2;
            *y -= 1;
            break;
        case 'G':
            floor[*x][*y] = number;
            number++;
            *x += 2;
            *y += 1;
            break;
        case 'H':
            floor[*x][*y] = number;
            number++;
            *x += 1;
            *y += 2;
            break;
    }
}