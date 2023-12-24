#include "jeucarte.h"
#include <random>
#include <algorithm>
#include <iostream>

void Card::display() const{
    std::cout << "(" << type << ", " << value << ")";
}

std::vector<Card> createDeck() {
    std::vector<std::string> types = {"Bâtons", "Coupes", "Épées", "Or"};
    std::vector<Card> deck;
    for (const auto& type : types) {
        for (int value = 1; value <= 7; ++value) {
            deck.push_back({type, value});
        }
        for (int value = 10; value <= 12; ++value) {
            deck.push_back({type, value});
        }
    }
    return deck;
}

void shuffleDeck(std::vector<Card>& deck) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
}

void dealCards(std::vector<Card>& deck, std::vector<std::vector<Card>>& players) {
    for (int i = 0; i < players.size(); ++i) {
        for (int j = 0; j < 4; ++j) {
            players[i].push_back(deck.back());
            deck.pop_back();
        }
    }
}

void displayPlayerHand(const std::vector<Card>& hand) {
    std::cout << "Cartes du joueur : ";
    for (const auto& card : hand) {
        card.display();
        std::cout << " ";
    }
    std::cout << std::endl;
}

bool isCardPlayable(const Card& card, const Card& middleCard) {
    return (card.type == middleCard.type || card.value == middleCard.value);
}

bool playCard(std::vector<Card>& playerHand, Card& middleCard, int cardIndex) {
    if (cardIndex < 0 || cardIndex >= playerHand.size()) {
        return false; // Carte invalide
    }
    // Logique pour jouer une carte et mettre à jour la carte du milieu, etc.
    return true;
}

// Implémentez d'autres fonctions en fonction de vos besoins de jeu spécifiques
