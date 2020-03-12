/* 7.17 (Simulation: The Tortoise and the Hare) In this problem, you’ll recreate one of the truly
great moments in history, namely the classic race of the tortoise and the hare. You’ll use random
number generation to develop a simulation of this memorable event.
Our contenders begin the race at “square 1” of 70 squares. Each square represents a possible
position along the race course. The finish line is at square 70. The first contender to reach or pass
square 70 is rewarded with a pail of fresh carrots and lettuce. The course weaves its way up the side
of a slippery mountain, so occasionally the contenders lose ground.
There’s a clock that ticks once per second. With each tick of the clock, your program should
adjust the position of the animals according to the rules:
Animal Move type Percentage of the time Actual move
           Move Type          Percentage of time         Actual move
Tortoise:
 	   Fast flod          %50			3 squares to the right
	   Slip               %20			6 squares to the left
	   Slow flod          %30			1 square to the right
Hare:
	   Sleep	          %20			No move at all
	   Big hop	          %20           9 squares to the right
	   Big slip           %10           12 squares to the left
	   Small hop          %30           1 square to the right
	   Small slip         %20           2 squares to the left
Use variables to keep track of the positions of the animals (i.e., position numbers are 1–70).
Start each animal at position 1 (i.e., the “starting gate”). If an animal slips left before square 1,
move the animal back to square 1. Generate the percentages in the preceding table by producing a
random integer, i, in the range 1 ≤ i ≤ 10. For the tortoise, perform a “fast plod” when 1 ≤ i ≤ 5, a
“slip” when 6 ≤ i ≤ 7, or a “slow plod” when 8 ≤ i ≤ 10. Use a similar technique to move the hare.
Begin the race by printing
BANG !!!!!
AND THEY'RE OFF !!!!!
Then, for each tick of the clock (i.e., each repetition of a loop), print a 70-position line showing
the letter T in the position of the tortoise and the letter H in the position of the hare. Occasionally,
the contenders will land on the same square. In this case, the tortoise bites the hare and your pro-
gram should print OUCH!!! beginning at that position. All print positions other than the T , the H , or
the OUCH!!! (in case of a tie) should be blank.
After each line is printed, test whether either animal has reached or passed square 70. If so,
then print the winner and terminate the simulation. If the tortoise wins, print TORTOISE WINS!!!
YAY!!! If the hare wins, print Hare wins. Yuch . If both animals win on the same tick of the clock,
you may want to favor the turtle (the “underdog”), or you may want to print It's a tie . If neither
animal wins, perform the loop again to simulate the next tick of the clock. When you’re ready to
run your program, assemble a group of fans to watch the race. You’ll be amazed at how involved
your audience gets!
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
void move_turtle(int *tlocation);
void move_rabbit(int *rlocation);
int main(){
    int turtle_location = 0;
    int rabbit_location = 0;
    int second = 1;
    while (turtle_location < 70 && rabbit_location < 70){
        printf("\n%d. Second in race:\n",second);
        move_turtle(&turtle_location);
        printf("Turtle location: %d\n",turtle_location);
        move_rabbit(&rabbit_location);
        printf("Rabbit location: %d\n",rabbit_location);
        second++;
        getch();
    }
    if (turtle_location >= rabbit_location){
        printf("Turtle show us If you work hard, nothing is impossible !!! Unbelivable");
    }
    else {
        printf("As guessed Rabbit has won");
    }

    return 0;
}
void move_turtle(int *tlocation){
    int a = rand()%10 + 1;
    if (a < 6){
        printf("\nTortoise made fast plod.\n");
        *tlocation += 3;
    }
    if (a < 8 && a > 5){
        printf("\nOww Tortoise is slipping.\n");
        if ((*tlocation - 6) < 0){
            *tlocation = 0;
        }
        else {
            *tlocation -= 6;
        }
    }
    if (a<11 && a > 7){
        printf("\n Tortoise made slow plod.\n");
        *tlocation += 1;
    }
}
void move_rabbit(int *rlocation){
    int a = rand()%10 +1;
    if (a > 0 && a < 3){
        printf("\nRabit is sleeping!!!!!ssssshhh Turtle gonna win\n");
    }
    if (a > 2 && a < 5 ){
        printf("\nRabit made big hop wow!\n");
        *rlocation += 9;
    }
    if (a < 6 && a > 4){
        printf("\nRabit is slipping well!\n");
        if ((*rlocation - 9 ) < 0){
            *rlocation = 0;
        }
        else {
            *rlocation -= 12;
        }
    }
    if (a > 5 && a < 9){
        printf("\nRabit made small hop.\n");
        *rlocation += 1;
    }
    if (a > 8 && a < 11){
        printf("\nRabit is slipping.\n");
        if ((*rlocation - 2 ) < 0){
            *rlocation = 0;
        }
        else {
            *rlocation -= 2;
        }
    }
}
