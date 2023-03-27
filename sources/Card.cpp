#include <iostream>
#include <cstdlib>
#include "card.hpp"

using namespace std;

namespace ariel
{

    Card::Card(Series series, Rank rank) : mySeries(series), myRank(rank){}
    Card::Card(){}

    Card::~Card(){}

    string Card::getRank()
    {
        return "rank of the card";
    }
    string Card::getSeries()
    {
        return "series of the card";
    }
    int Card::getRankValue()
    {
        return 0;
    }
}