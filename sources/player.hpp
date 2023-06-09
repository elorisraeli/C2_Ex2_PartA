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

    public:
        Player(string name);



        int stacksize();
        int cardesTaken();
        Card playCard();
        void addCardsWon(vector<Card> wonDeck);
        string getName();
    };
}
#endif
