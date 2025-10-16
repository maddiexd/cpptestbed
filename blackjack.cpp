#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <random>

int blJaPoints[] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
std::string cardNames[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
std::string suitNames[] = {"Diamonds", "Hearts", "Clubs", "Spades"};
std::mt19937 mt{std::random_device{}()};

int checkBlJaWin(int playerPoints, int dealerPoints) {
    if (((playerPoints > dealerPoints) || dealerPoints > 21) && playerPoints <= 21) {
        return 1;
    }
    else if ((playerPoints < dealerPoints || (playerPoints > 21)) && dealerPoints <= 21) {
        return 0;
    }
    else {
        return 2;
    }
}

std::string beautifyCard(int card) {
    return cardNames[(card % 13)] + " of " + suitNames[(card / 13)];
}

class deckOfCards{
    private:
        std::vector<int> deck;
    public:
        deckOfCards() {
            for (int i = 0; i < 52; i++) {
                deck.push_back(i);
            }
            std::shuffle(deck.begin(), deck.end(), mt); // shuffles deck
        }
        int pickACard() { // Draws a random card. Significantly more efficient due to pre-shuffled deck
            if (!deck.empty()) {
                int card = deck.back();
                deck.pop_back();
                return card;
            } else {
                return -1;
            };
        }
};

class hand{
    private:
        std::vector<int> cards;
    public:
        void draw(deckOfCards &deck, int amount) {
            for (int i = 0; i < amount; i++) {
                cards.push_back(deck.pickACard());
            }
        }
        int draw(deckOfCards &deck) {
            int card = deck.pickACard();
            cards.push_back(card);
            return card;
        }
        int getPoints() {
            int acecount = 0;
            int total = 0;
            for (int card : cards) {
                total += blJaPoints[(card % 13)];
                if (card % 13 == 0) {
                    acecount++;
                }
            }
            for (;(acecount > 0 && total > 21); acecount--) {
                total -= 10;
            }
            return total;
        }
        std::vector<int> getCards() {
                return cards;
        }
        void printStatus() {
            std::cout << "Cards: " << std::endl;
            for (int card : cards) {
                std::cout << beautifyCard(card) << std::endl;
            }
            std::cout << "Points: "<< getPoints() << std::endl;

        }
};


void blackJack() {
    deckOfCards topdeck; 
    hand player, dealer;
    player.draw(topdeck, 1);
    int dealerCard = dealer.draw(topdeck);
    std::cout << "The dealer draws the "<< beautifyCard(dealerCard) << std::endl;
    player.draw(topdeck, 1);
    dealer.draw(topdeck, 1);
    player.printStatus();

    bool stand = false, invalidInput = false;
    while (dealer.getPoints() + player.getPoints() <= 42) { // keeps going if someone can play
        if (stand == false && (player.getPoints() <= 21)) { // checks if the player can play
            std::cout << "Hit (h) or stand (s)?" << std::endl;
            std::string choice;
            std::cin >> choice;

            switch (choice[0]) {
                case 's':
                    std::cin.clear();
                    stand = true;
                    invalidInput = false;
                    break;
                case 'h':
                    std::cin.clear();
                    player.draw(topdeck, 1);
                    invalidInput = false;
                    player.printStatus();
                    break;
                default:
                    invalidInput = true;
                    std::cout << "invalid input\n";
                    std::cin.clear();
            }
        }
        else if (stand && !invalidInput && (dealer.getPoints() < 17)) { //checks if the dealer should hit
            std::cout << "Dealer hits!" << std::endl;
            dealer.draw(topdeck, 1);
        }
        else { // breaks out of the loop if none play
            break;
        }
    }
    // final winning message
    int outcome = checkBlJaWin(player.getPoints(), dealer.getPoints());
    std::string winString[] = {"Lose", "Win", "Draw"};
    std::cout << "You "<< winString[outcome] << "! The dealer's status: "<< std::endl;
    dealer.printStatus();
}

int main() {
    std::string choice;
    bool continu = true;
    while (continu) {
        blackJack();
        std::cout << "Play Again? (y/n)";
        std::cin >> choice;
        switch (choice[0]) {
            case 'n':
                continu = false;
                break;
            default:
                break;
        }

    }
    return 0;
}