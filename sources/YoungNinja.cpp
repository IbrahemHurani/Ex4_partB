#include "Character.hpp"
#include "YoungNinja.hpp"
using namespace std;
namespace ariel
{
    YoungNinja::YoungNinja()
    {
    }
    YoungNinja::YoungNinja(string name, const Point &location) : Ninja(name, location)
    {
        this->setType("N");
        this->setHit(100);
        this->setSpeed(14);
    }
   

};