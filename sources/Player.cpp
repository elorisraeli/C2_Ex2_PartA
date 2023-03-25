#include "player.hpp"
#include "card.hpp"
#include <vector>
#include <string>

using namespace std;

namespace ariel
{
    Player::Player(const string &name) : mName(name)
    {
    }

    Player::~Player() {}

    int Player::stacksize()
    {
        return 0;
    }

    int Player::cardesTaken()
    {
        return 0;
    }


}