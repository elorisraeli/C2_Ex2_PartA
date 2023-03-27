#include "player.hpp"
#include "card.hpp"
#include <vector>
#include <string>

using namespace std;

namespace ariel
{
    Player::Player(string name) : mName(name) {}

    int Player::stacksize()
    {
        return 0;
    }

    int Player::cardesTaken()
    {
        return 0;
    }

    Card Player::playCard()
    {
        return Card();
    }

    void Player::addCardsWon(vector<Card> wonDeck)
    {
    }

    string Player::getName()
    {
        return mName;
    }

}