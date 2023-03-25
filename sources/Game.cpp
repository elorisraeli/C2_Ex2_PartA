#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "game.hpp"
#include "player.hpp"

using namespace std;

namespace ariel
{
    Game::Game(Player p1, Player p2) : p1(p1), p2(p2)
    {
        turns = 0;
        draws = 0;
    }

    Game::~Game()
    {
    }

    void Game::addToLog(const string &str)
    {
        log.push_back(str);
    }

    void Game::playTurn()
    {
        vector<Card> turnCards;

        Card p1Card = p1.playCard();
        Card p2Card = p2.playCard();

        turnCards.push_back(p1Card);
        turnCards.push_back(p2Card);

        string turnString = p1.getName() + " played " + p1Card.getRank() + " of " + p1Card.getSeries() + " " + p2.getName() + " played " + p2Card.getRank() + " of " + p2Card.getSeries() + ". ";

        bool draw = false;
        if (p1Card.getRankValue() == p2Card.getRankValue())
        {
            draw = true;
        }
        // while draw
        while (draw == true)
        {
            turnString.append("Draw. ");
            // first option out of cards
            if (p1.stacksize() == 0 || p2.stacksize() == 0)
            {
                break;
            }
            // if not out of cards: continue the draw breakdown
            // simulate of opposite down cards - go inside the cards deck of turn without consider their value
            Card p1AnotherCard = p1.playCard();
            Card p2AnotherCard = p2.playCard();
            turnCards.push_back(p1AnotherCard);
            turnCards.push_back(p2AnotherCard);

            // second option out of cards while the card are "opposite down"
            if (p1.stacksize() == 0 || p2.stacksize() == 0)
            {
                // return each player his cards (each got on)
                break;
            }
            // if their both left cards in stack, then start the loop until winner accur or out of cards

            turnString.append(p1.getName() + " played " + p1AnotherCard.getRank() + " of " + p1AnotherCard.getSeries() + " " 
                            + p2.getName() + " played " + p2AnotherCard.getRank() + " of " + p2AnotherCard.getSeries() + ". ");

            if (p1AnotherCard.getRankValue() != p2AnotherCard.getRankValue())
            {
                draw = false;
            }
            
        }

        if (p1Card.getRankValue() > p2Card.getRankValue())
        {
            turnString.append(p1.getName() + " wins.");
            while (turnCards.empty() == false)
            {
                Card currentTopCard = turnCards.front();
                turnCards.erase(turnCards.begin());
                p1.addCardWon(currentTopCard);
            }
        }
        else if (p1Card.getRankValue() < p2Card.getRankValue()) // could be just else
        {
            turnString.append(p2.getName() + " wins.");
            while (turnCards.empty() == false)
            {
                Card currentTopCard = turnCards.front();
                turnCards.erase(turnCards.begin());
                p2.addCardWon(currentTopCard);
            }
        }
        else // no one win and out of cards
        {
            bool even = true;
            while (turnCards.empty() == false)
            {
                Card currentTopCard = turnCards.front();
                turnCards.erase(turnCards.begin());
                if (even)
                {
                    p1.addCardWon(currentTopCard);
                }
                else
                {
                    p2.addCardWon(currentTopCard);
                }
            }
        }

        addToLog(turnString);
    }

    void Game::printLastTurn()
    {
        cout << log.back();
    }

    void Game::playAll()
    {
        
    }


    void Game::printWiner()
    {
        if (p1.stacksize() == 0)
        {
            cout << p1.getName() << endl;
        }
        else if (p2.stacksize() == 0)
        {
            cout << p2.getName() << endl;
        }
        else
        {
            cout << "No winner yet" << endl;
        }
    }
    void Game::printLog()
    {
        for (const auto &line : log)
        {
            cout << line << endl;
        }
    }
    void Game::printStats()
    {
    }

}