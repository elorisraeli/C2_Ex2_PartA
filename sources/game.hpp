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
        Player p1;
        Player p2;
        int draws;
        int turns;
        vector<string> log;

    public:
        Game(Player p1, Player p2);
        ~Game();

        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();

        void addToLog(const string& str);

    };
}
#endif // GAME_HPP
