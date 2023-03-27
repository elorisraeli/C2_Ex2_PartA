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
    Game::Game(Player player1, Player player2) : player1(player1), player2(player2) {}

    void Game::playTurn()
    {
    }

    void Game::printLastTurn()
    {
    }

    void Game::playAll()
    {
    }

    void Game::printWiner()
    {
    }
    void Game::printLog()
    {
    }
    void Game::printStats()
    {
    }

    void Game::addToLog(string str)
    {
    }

    void Game::shuffleDeckAndGivePlayers()
    {
    }

    string Game::getDrawsString()
    {
        return "";
    }
    string Game::getTurnsPlayedString()
    {
        return "";
    }

}