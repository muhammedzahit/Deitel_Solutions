/*
(Airline Reservations System) A small airline has just purchased a computer for its new au-
tomated reservations system. The president has asked you to program the new system. You’ll write
a program to assign seats on each flight of the airline’s only plane (capacity: 10 seats).
Your program should display the following menu of alternatives:
Please type 1 for "first class"
Please type 2 for "economy"
If the person types 1, then your program should assign a seat in the first class section (seats 1–
5). If the person types 2, then your program should assign a seat in the economy section (seats 6–
10). Your program should then print a boarding pass indicating the person's seat number and
whether it’s in the first class or economy section of the plane.
Use a single-subscripted array to represent the seating chart of the plane. Initialize all the ele-
ments of the array to 0 to indicate that all seats are empty. As each seat is assigned, set the corre-
sponding element of the array to 1 to indicate that the seat is no longer available.
Your program should, of course, never assign a seat that has already been assigned. When the
first class section is full, your program should ask the person if it’s acceptable to be placed in the
economy section (and vice versa). If yes, then make the appropriate seat assignment. If no, then
print the message "Next flight leaves in 3 hours."
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int *seats = malloc(4*10);
    int s;
    for (s=0; s<10; s++){
        seats[s] = 0;
    }
    int sum=0;
    while (sum != 10){
        sum =0;
        printf("Welcome Aydinlar Airways :)\n");
        printf("For business enter 1\nFor economic enter 2\n");
        int flightClass;
        scanf("%d",&flightClass);
        if (flightClass == 1){
            for (s=0; s<5; s++){
                if (seats[s] == 0){
                    break;
                }
            }

            if (s == 5){
                char c;
                printf("We didn't find business ticket for you\nAre you want economic ticket for this flight ?(y/n)\n");
                scanf(" %c",&c);
                if (c == 'y'){
                    for (s=5; s<10; s++){
                        if (seats[s] == 0){
                            break;
                        }
                    }
                    if (s == 10){
                        printf("Sorry we didn't find seat for you.\nNext flight after 3 hours. Good luck.\n");
                    }
                    else {
                        seats[s] = 1;
                        printf("Your seat number is %d Good Journey\n",s+1);
                    }
                }

                else {
                    printf("Next flight after 3 hours. Good luck. \n");
                }

            }
            else{
                seats[s] = 1;
                printf("Your seat number is %d , Good journeys :)\n",s+1);
            }
        }
        if (flightClass == 2){
            for (s=5; s<10; s++){
                if (seats[s] == 0){
                    break;
                }
            }
            if (s == 10){
                char d;
                printf("We didn't find business ticket for you\nAre you want business ticket for this flight(y/n)?    ");
                scanf(" %c",&d);
                if (d == 'y'){
                    for (s=0; s<5; s++){
                        if (seats[s] == 0){
                            break;
                        }
                    }

                    if (s == 5){
                        printf("Next flight after 3 hours. Good luck.\n");
                    }
                    else{
                        seats[s] = 1;
                        printf("Your seat number is %d , Good journeys :)\n",s+1);
                    }
                }
                else {
                    printf("Next flight after 3 hours. Good luck. \n");
                }
            }
            else {
                seats [s] = 1;
                printf("Your seat number is %d , Good journeys :) \n",s+1);
            }
        }
        for (s=0; s<10; s++){
            sum += seats[s];
        }
    }
    free(seats);
    printf("\n\nSorry our flight is full :(\n\n");
    return 0;
}