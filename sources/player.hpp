#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "card.hpp"
#include <vector>

using namespace std;

namespace ariel
{
    class Player
    {
    private:
        string mName;
        vector<Card> myStack;
        vector<Card> myTakens;

    public:
        Player(const string &name);
        ~Player();

        int stacksize();
        int cardesTaken();

        void addCard(const Card& card);
        void addCardWon(const Card& card);
        Card playCard();
        const string& getName();
    };
}
#endif
