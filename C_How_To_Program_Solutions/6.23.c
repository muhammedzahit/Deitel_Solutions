/*(Turtle Graphics) The Logo language made the concept of turtle graphics famous. Imagine
a mechanical turtle that walks around the room under the control of a C program. The turtle holds
a pen in one of two positions, up or down. While the pen is down, the turtle traces out shapes as it
moves; while the pen is up, the turtle moves about freely without writing anything. In this problem
you’ll simulate the operation of the turtle and create a computerized sketchpad as well.
Use a 50-by-50 array floor which is initialized to zeros. Read commands from an array that
contains them. Keep track of the current turtle position at all times and whether the pen is cur-
rently up or down. Assume that the turtle always starts at position 0, 0 of the floor with its pen up.
The set of turtle commands your program must process are shown in Fig. 6.25. Suppose that the
turtle is somewhere near the center of the floor. The following “program” would draw and print a
12-by-12 square:
2
5,12
3
5,12
3
5,12
3
5,12
1
6
9
As the turtle moves with the pen down, set the appropriate elements of array floor to 1 s. When the
6 command (print) is given, wherever there’s a 1 in the array, display an asterisk, or some other
character you choose. Wherever there’s a zero, display a blank. Write a program to implement the
turtle graphics capabilities discussed here. Write several turtle graphics programs to draw interest-
ing shapes. Add other commands to increase the power of your turtle graphics language.
Command Meaning
1---> Pen up
2---> Pen down
3---> Turn right
4---> Turn left
5,x(10)---> Move forward 10 spaces (or a number other than 10)
6---> Print the 50-by-50 array
9--->End of data (sentinel)

Program:
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void turnRight(int *direction);
void turnLeft(int *direction);
void showDirection(int *direction);
void move(int floor[50][50],int numberofMove,int direction,int pen,int *a,int *b);
int main(){
    printf("                TURTLE GRAPHICS\n");
    srand(time(NULL));
    int s,i,flag=0;
    int floor[50][50]={0};
    // 0-> Down , 1-> Left , 2-> Up , 3-> Right
    int direction = 0;
    // 0-> Write , 1 -> hold
    int pen = 1;
    int x= rand()%50; //TURTLE LOCATION X
    int y= rand()%50;// TURTLE LOCATION Y
    int selection,number;
    printf("Your turtle random location ->  x: %d  y: %d\n",x,y);
    printf("Your turtle direction is down.");
    printf("\nYour turtle pen mode is hold.\n");
    while (flag == 0){
        printf("1- Pen write mode\n");
        printf("2- Pen hold mode\n");
        printf("3- Turtle turn right\n");
        printf("4- Turtle turn left\n");
        printf("5- Move n spaces\n");
        printf("6- Print floor\n");
        printf("9- End program\n");
        printf("Enter selection: ");
        scanf("%d",&selection);
        switch(selection){
            case 1:
                pen = 0;
                break;
            case 2:
                pen = 1;
                break;
            case 3:
                turnRight(&direction);
                showDirection(&direction);
                break;
            case 4:
                turnLeft(&direction);
                showDirection(&direction);
                break;
            case 5:
                scanf("%d",&number);
                move(floor,number,direction,pen,&x,&y);
                printf("\nYour turtle new location ->  x: %d  y: %d\n",x,y);
                break;
            case 6:
                for (s=0; s<50; s++){
                    printf("-");
                }
                printf("\n");
                for (s=0; s<50; s++){
                    printf("|");
                    for (i=0; i<50; i++){
                        if (s==x && i==y) {
                            printf("T");
                        }
                        else if (floor[s][i] == 1){
                            printf("*");
                        }
                        else {
                            printf(" ");
                        }
                    }
                    printf("|");
                    printf("\n");
                }
                for (s=0; s<50; s++){
                    printf("-");
                }
                printf("\n");
                break;
            case 9:
                flag = 1;
                break;
        }
    }
    return 0;
}
void showDirection(int *direction){
    // 0-> Down , 1-> Left , 2-> Up , 3-> Right
    switch(*direction){
        case 0:
            printf("\nYour direction is down.\n");
            break;
        case 1:
            printf("\nYour direction is left.\n");
            break;
        case 2:
            printf("\nYour direction is up.\n");
            break;
        case 3:
            printf("\nYour direction is right.\n");
            break;
    }
}
void turnRight(int *direction){
    if (*direction == 3 ){
        *direction = 0;
    }
    else {
        *direction += 1;
    }
}
void turnLeft(int *direction){
    if (*direction == 0){
        *direction = 3;
    }
    else {
        *direction -=1;
    }
}
void move(int floor[50][50],int numberofMove,int direction,int pen,int *a,int *b){
    int s,i;
    int x=*a,y=*b;
    if (pen == 1){
        if (direction == 0){
            if (x+numberofMove>49){
                printf("Your move is wrong.");
            }
            else {
                x+= numberofMove;
                printf("%d\n",x);
                *a = x;
            }
        }
        if (direction == 1){
            if (y-numberofMove < 0){
                printf("Your move is wrong.");
            }
            else {
                y -= numberofMove;
                *b = y;
            }
        }
        if (direction == 2){
            if (x-numberofMove < 0){
                printf("Your move is wrong.");
            }
            else {
                x-= numberofMove;
                *a = x;
            }
        }
        if (direction == 3){
            if (y+numberofMove > 49){
                printf("Your move is wrong.");
            }
            else {
                y += numberofMove;
                *b = y;
            }
        }
    }
    else {
        if (direction == 0){
            if (x+numberofMove>49){
                printf("Your move is wrong.");
            }
            else {
                for (s=0; s<numberofMove; s++){
                    floor[x+s][y]=1;
                }
                x +=numberofMove;
                *a = x;
            }
        }
        if (direction == 1){
            if (y-numberofMove < 0){
                printf("Your move is wrong.");
            }
            else {
                for (s=0; s<numberofMove; s++){
                    floor[x][y-s] = 1;
                }
                y -= numberofMove;
                *b = y;
            }
        }
        if (direction == 2){
            if (x-numberofMove < 0){
                printf("Your move is wrong.");
            }
            else {
                for (s=0; s<numberofMove; s++){
                    floor[x-s][y] = 1;
                }
                x-= numberofMove;
                *a = x;
            }
        }
        if (direction == 3){
            if (y+numberofMove > 49){
                printf("Your move is wrong.");
            }
            else {
                for (s=0; s<numberofMove; s++){
                    floor[x][y+s] = 1;
                }
                y += numberofMove;
                *b = y;
            }
        }
    }
}

