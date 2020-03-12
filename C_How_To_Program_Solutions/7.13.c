/*7.12 (Card Shuffling and Dealing) Modify the program in Fig. 7.24 so that the card-dealing
function deals a five-card poker hand. Then write the following additional functions:
a) Determine whether the hand contains a pair.
b) Determine whether the hand contains two pairs.
c) Determine whether the hand contains three of a kind (e.g., three jacks).
d) Determine whether the hand contains four of a kind (e.g., four aces).
e) Determine whether the hand contains a flush (i.e., all five cards of the same suit).
f) Determine whether the hand contains a straight (i.e., five cards of consecutive face values).
7.13 (Project: Card Shuffling and Dealing) Use the functions developed in Exercise 7.12 to
write a program that deals two five-card poker hands, evaluates each, and determines which is the
better hand.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void shuffle(int array[4][13]);
void initializeHand(int hand[],int deck[4][13]);
int showHand(int hand[],char *suit[],char *face[]);
int main(){
    int s,i;
    char *suit[4]={"Hearts","Diamonds","Clubs","Spades"};
    char *face[13]={"Ace","Deuce","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
    int deck[4][13]={0};
    srand(time(NULL));
    shuffle(deck);
    int hand[5];
    int hand2[5];
    initializeHand(hand,deck);
    initializeHand(hand2,deck);
    printf("\nHAND 1:\n");
    int hand1Point= showHand(hand,suit,face);
    printf("\nPOINT---> %d\n",hand1Point);
    printf("\nHAND 2:\n");
    int hand2Point= showHand(hand2,suit,face);
    printf("\nPOINT---> %d\n",hand2Point);
    if (hand1Point == hand2Point){
        printf("\nEQUAL\n");
    }
    else if(hand1Point > hand2Point){
        printf("\nHAND 1 LUCKY THAN HAND 2\n");
    }
    else {
        printf("\nHAND 2 LUCKY THAN HAND 1\n");
    }
    return 0;
}
void shuffle(int array[4][13]){
    int i,row,clmn;
    for (i=0; i<52; i++){
        do {
            row = rand()%4;
            clmn = rand()%13;

        }while ( array[row][clmn] != 0 );

        array[row][clmn] = i;

    }
}
void initializeHand(int hand[],int deck[4][13]){
    int s,rndm,rndm2;
    for (s=0; s<5; s++){
        do {
            rndm= rand()%4;
            rndm2 = rand()%13;
        }while ( deck[rndm][rndm2] == -1 );
        hand[s] = deck[rndm][rndm2];
        deck[rndm][rndm2] = -1;
    }
}
int showHand(int hand[],char *suit[],char *face[]){
    int s,point=0;
    int array[13]={0};
    for (s=0; s<5; s++){
        int a = hand[s]/13;
        int b = hand[s]-(13*(hand[s]/13));
        printf("%12s%12s\n",suit[a],face[b]);
        ++array[b];
    }
    printf("\n");
    for (s=0; s<13; s++){
        int counter=0;
        if (array[s] == 1 && array[s+1] == 1 && array[s+2] == 1 && array[s+3] ==1 && array[s+4] == 1){
            printf("a");
            point += 3;
        }
        if (array[s] == 2){
            printf("You have two pairs %s\n",face[s]);
            point += 2;
        }
        if (array[s] == 3){
            printf("You have three %s\n",face[s]);
            point += 3;
        }
        if (array[s] == 4){
            printf("You have four %s\n",face[s]);
            point += 4;
        }
        if (array[s] == 5){
            printf("WOW ! FLUSH !!!!! HOW LUCKY YOU ARE !");
            point += 5;
        }
    }
    return point;
}