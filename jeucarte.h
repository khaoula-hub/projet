#ifndef JEUCARTE_H
#define JEUCARTE_H

#include <vector>
#include <iostream>

struct Card {
    std::string type;
    int value;
    void display() const;
};

std::vector<Card> createDeck();
void shuffleDeck(std::vector<Card>& deck);
void dealCards(std::vector<Card>& deck, std::vector<std::vector<Card>>& players);
void displayPlayerHand(const std::vector<Card>& hand);
bool isCardPlayable(const Card& card, const Card& middleCard);
bool playCard(std::vector<Card>& playerHand, Card& middleCard, int cardIndex);
//bool drawAndPlay(std::vector<Card>& playerHand, std::vector<Card>& deck, Card& middleCard);

#endif // JEUCARTE_H
