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
        Player(const string &name);
        ~Player();

        int stacksize();
        int cardesTaken();
    };
}
#endif
