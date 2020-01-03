#include "card.hpp"
#include <iostream>
using namespace std;

string faces[] = {"Ace","Deuce","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
                "Jack","Queen","King"};

string suits[] = {"Hearts","Diamonds","Clubs","Spades"};

void Card::showCardName(){
    cout << faces[face-1] << " of " << suits[suit-1] << endl;
}
// int face , int suit
Card::Card(int face,int suit)
{
    this->face = face;
    this->suit = suit;
}

void Card::setFace(int a){
    face = a;
}

void Card::setSuit(int a){
    suit = a;
}

int Card::getHand(){
    return hand;
}

void Card::setHand(){
    hand = 1;
}

int Card::getFace(){
    return face;
}

int Card::getSuit(){
    return suit;
}

void Card::printSuit(){
    cout << suits[suit-1];
}