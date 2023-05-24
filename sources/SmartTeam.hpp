#ifndef SmartTeam_HPP
#define SmartTeam_HPP
#include <vector>

#include "Team.hpp"
using namespace std;
namespace ariel
{
    class SmartTeam : public Team
    {
    private:
    public:
        SmartTeam();
        SmartTeam(Character *);
    };

}
#endif