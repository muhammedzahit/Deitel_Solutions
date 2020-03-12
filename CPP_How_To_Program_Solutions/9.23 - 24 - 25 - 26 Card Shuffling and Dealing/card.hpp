#ifndef CARD_HPP
#define CARD_HPP
#include <iostream>
using namespace std;
class Card{
private:
    int face,suit;
    int hand = 0;
public:
    void showCardName();
    Card(int=0,int=0);
    void setFace(int);
    void setSuit(int);
    int getHand();
    void setHand();
    int getFace();
    int getSuit();
    void printSuit();
};

#endif
