#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "doctest.h"

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace std;
using namespace ariel;

/*
For the game rules:
Assume that when player won turn, the stack of the turn goes into hos currect stack immediatly
*/

TEST_CASE("Test 1 - Initialization")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);

    int p1Size = p1.stacksize();
    int p2Size = p2.stacksize();

    CHECK_EQ(p1Size, p2Size);

    CHECK(p1Size == 26);
    CHECK(p2Size == 26);
}

TEST_CASE("Test 2 - One turn played")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    game.playTurn();
    // options after one turn
    bool isOk = (p1.stacksize() > p2.stacksize() || p1.stacksize() < p2.stacksize() || p1.stacksize() == p2.stacksize());
    CHECK(isOk == true);
}

TEST_CASE("Test 3 - There is Winner")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    game.playTurn();

    bool isP1Win = (p1.cardesTaken() % 2 == 0 && p1.stacksize() % 2 == 0);
    bool isP2Win = (p2.cardesTaken() % 2 == 0 && p2.stacksize() % 2 == 0);
    bool isDrawP1Win = (p1.cardesTaken() % 2 == 0 && p1.stacksize() % 2 == 0);
    bool isDrawP2Win = (p2.cardesTaken() % 2 == 0 && p2.stacksize() % 2 == 0);

    bool together = (isP1Win || isP2Win || isDrawP1Win || isDrawP2Win);
    CHECK(together == true);
}

TEST_CASE("Test 4 - Play All the game")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    game.playAll();

    int p1Size = p1.stacksize();
    int p2Size = p2.stacksize();

    // must to be a winner
    bool p1Won = (p1Size == 52 && p2Size == 0);
    bool p2Won = (p1Size == 0 && p2Size == 52);
    bool winner = (p1Won || p2Won);
    CHECK(winner == true);

    CHECK_NE(p1Size, p2Size);
}

TEST_CASE("Test 5 - Winner in turn")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    game.playTurn();

    bool turn1Winner = (p1.cardesTaken() > 0 || p2.cardesTaken() > 0);
    bool winEvenCards = (p1.cardesTaken() % 2 == 0 || p2.cardesTaken() % 2 == 0);

    CHECK(turn1Winner == true);
    CHECK(winEvenCards == true);
}

TEST_CASE("Test 6 - Last turn print fine")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    game.playTurn();

    // check if no throw exception
    CHECK_NOTHROW(game.printLastTurn());
}

TEST_CASE("Test 7 - Winner print fine")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    game.playTurn();

    // check if no throw exception
    CHECK_NOTHROW(game.printWiner());
}

TEST_CASE("Test 8 - Log print fine")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    game.playTurn();

    // check if no throw exception
    CHECK_NOTHROW(game.printLog());
}

TEST_CASE("Test 9 - Stats print fine")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    game.playTurn();

    // check if no throw exception
    CHECK_NOTHROW(game.printStats());
}

TEST_CASE("Test 10 - Get Card from player")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    // check if no throw exception
    CHECK_NOTHROW(p1.playCard());
    CHECK_NOTHROW(p2.playCard());
}

TEST_CASE("Test 11 - Add Deck to winner")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    vector<Card> wonDeck;
    wonDeck.push_back(p1.playCard());
    wonDeck.push_back(p2.playCard());
    CHECK_NOTHROW(p1.addCardsWon(wonDeck));
}

TEST_CASE("Test 12 - Add to Log")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    CHECK_NOTHROW(game.addToLog("data"));
}

TEST_CASE("Test 13 - Card Get Rank Value")
{
    Card c1;
    int rank = c1.getRankValue();

    CHECK_EQ(rank, 0);
}

TEST_CASE("Test 14 - Card Get Rank String")
{
    Card c1;
    CHECK_NOTHROW(c1.getRank());
}

TEST_CASE("Test 15 - Card Get Series String")
{
    Card c1;
    CHECK_NOTHROW(c1.getSeries());
}

TEST_CASE("Test 16 - Players Name String")
{
    string p1Name = "Alice";
    string p2Name = "Bob";
    Player p1(p1Name);
    Player p2(p2Name);

    CHECK_EQ(p1.getName(), p1Name);
    CHECK_EQ(p2.getName(), p2Name);
}

TEST_CASE("Test 17 - Shuffle deck and distribute to players")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    CHECK_NOTHROW(game.shuffleDeckAndGivePlayers());
}

TEST_CASE("Test 18 - Get number of draws string")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    string draws = game.getDrawsString();
    CHECK_NE(draws, "");
}

TEST_CASE("Test 19 - Get number of turns played string")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    string turnsPlayed = game.getTurnsPlayedString();
    CHECK_NE(turnsPlayed, "");
}

TEST_CASE("Test 20 - Main Run Good")
{
    // Create two players with their names
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);
    for (int i = 0; i < 5; i++)
    {
        CHECK_NOTHROW(game.playTurn());
    }
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(p1.stacksize());
    CHECK_NOTHROW(p2.cardesTaken());
    CHECK_NOTHROW(game.playAll());
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printStats());
}
