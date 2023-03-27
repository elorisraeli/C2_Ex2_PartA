#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>
#include "player.hpp"
using namespace std;

namespace ariel
{
    class Game
    {
    private:
        Player player1;
        Player player2;

    public:
        Game(Player player1, Player player2);

        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();

        void addToLog(string str);
        void shuffleDeckAndGivePlayers();

        string getDrawsString();
        string getTurnsPlayedString();
    };
}
#endif // GAME_HPP
