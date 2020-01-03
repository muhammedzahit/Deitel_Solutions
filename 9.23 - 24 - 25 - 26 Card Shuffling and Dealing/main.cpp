#include <iostream>
#include "card.hpp"
#include "deck.hpp"
using namespace std;
int main(){
    Deck deck1;
    deck1.shuffleDeck();
    int player1[5];
    int player2[5];
    deck1.dealFiveCard(player1);
    deck1.dealFiveCard(player2);
    cout << endl << "Player 1 Hand" << endl;
    for (int i=0; i<=4; i++){
        deck1.showCardName(player1[i]);
    }
    int player1_point = deck1.checkfive(player1);
    cout << endl << "Player 2 Hand " << endl;
    for (int i=0; i<=4; i++){
        deck1.showCardName(player2[i]);
    }
    int player2_point = deck1.checkfive(player2);
    if (player1_point > player2_point){
        cout << "Player1's hand better " << endl;
    }
    else if (player1_point == player2_point) cout << "Draw" << endl;
    else cout << "Player2's hand better " << endl;
}