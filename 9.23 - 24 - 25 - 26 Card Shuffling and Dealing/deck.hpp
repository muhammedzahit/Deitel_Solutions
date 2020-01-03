#ifndef DECK_HPP
#define DECK_HPP
#include "card.hpp"

class Deck{
private:
    Card cards[52];
public:
    Deck();
    void showDeck();
    void shuffleDeck();
    void dealFiveCard(int player[]);
    void showCardName(int);
    int checkfive(int player[]);
};

#endif

