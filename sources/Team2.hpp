#ifndef TEAM2_HPP
#define TEAM2_HPP
#include <vector>
#include "Team.hpp"
using namespace std;
namespace ariel
{
    class Team2 : public Team
    {
    private:

    public:
        Team2();
        Team2(Character *);
        void add(Character *);
    };

};
#endif