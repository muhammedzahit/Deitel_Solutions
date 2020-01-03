#include <iostream>
#include "card.hpp"
#include "deck.hpp"
#include <random>
#include <ctime>
default_random_engine generator(time(0));
uniform_int_distribution<int> distribution(0,52);
Deck::Deck()
{   
    int i = 0;
    for (int a = 1 ; a<=4 ; a++){
        for (int b=1; b<=13; b++){
            cards[i].setSuit(a);
            cards[i].setFace(b);
            i++;
        }
    }
}

void Deck::showDeck(){
    for (int i=0; i<=51; i++){
        cards[i].showCardName();
        if (i+1 % 4 == 0) cout << endl;
    }
}

void Deck::shuffleDeck(){
    Card temp;
    int a;
    for (int i=0; i<=51; i++){
        a = distribution(generator);
        temp = cards[i];
        cards[i] = cards[a];
        cards[a] = temp;
    }
}

void Deck::dealFiveCard(int player[]){
    int a;
    for (int i=0; i<=4; i++){
        a = distribution(generator);
        while (cards[a].getHand() != 0){
            a = distribution(generator);
        }
        player[i] = a;
        cards[a].setHand();
    }
}

void Deck::showCardName(int a){
    cards[a].showCardName();
}


void sayacControl(int sayac,int i,int *point){
    string suits[] = {"Hearts","Diamonds","Clubs","Spades"};
    if (sayac == 2){
        cout << "You have pairs of " << suits[i-1] << endl;
        *point += 1;
    }
    if (sayac == 3){
        cout << "You have three of a kind " << suits[i-1] << endl;
        *point += 2;
    }
    if (sayac == 4){
        cout << "You have four of a kind " << suits[i-1] << endl;
        *point += 3;
    }
    if (sayac == 5){
        cout << "You have flash of " << suits[i-1] << endl;
        *point += 4;
    }
}

int Deck::checkfive(int player[]){
    int sayac,point=1;
    for (int i=1; i<= 4; i++){
        sayac = 0;
        for (int a =0; a<=4 ; a++){
            if (i == cards[player[a]].getSuit()) sayac++;
        }
        sayacControl(sayac,i,&point);
    }
    return point;
}