#include "TrainedNinja.hpp"
#include "Character.hpp"
using namespace std;
namespace ariel
{
    TrainedNinja::TrainedNinja()
    {
    }
    TrainedNinja::TrainedNinja(string name, const Point &location) : Ninja(name, location)
    {
        this->setType("N");
        this->setSpeed(12);
        this->setHit(120);
    }
   
    

};