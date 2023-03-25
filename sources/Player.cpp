#include "player.hpp"
#include "card.hpp"
#include <vector>
#include <string>

using namespace std;

namespace ariel
{
    vector<Card> myStack;

    vector<Card> myTakens;

    // create the deck of cards
    void getDeck()
    {
        for (int i = static_cast<int>(Card::Series::HEARTS); i <= static_cast<int>(Card::Series::SPADES); i++)
        {
            for (int j = static_cast<int>(Card::Rank::ACE); j <= static_cast<int>(Card::Rank::KING); j++)
            {
                Card::Series series = static_cast<Card::Series>(i);
                Card::Rank rank = static_cast<Card::Rank>(j);
                Card card(series, rank);

                myStack.push_back(card);
            }
        }
    }

    Player::Player(const string &name) : mName(name)
    {
        getDeck();
    }

    Player::~Player() {}

    int Player::stacksize()
    {
        return myStack.size();
    }

    int Player::cardesTaken()
    {
        return myTakens.size();
    }

    void Player::addCard(const Card &card)
    {
        myStack.push_back(card);
    }

    void Player::addCardWon(const Card &card)
    {
        myTakens.push_back(card);
    }

    Card Player::playCard()
    {
        Card currentTopCard = myStack.front();
        myStack.erase(myStack.begin());
        return currentTopCard;
    }

    const string& Player::getName()
    {
        return mName;
    }

}