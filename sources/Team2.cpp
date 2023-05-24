#include "Team2.hpp"
using namespace std;
namespace ariel
{
    Team2::Team2(Character *lead) :Team(lead)
    {
        
        
    }
    void Team2::add(Character* new_warrior){
        vector<Character*> group;
        if (new_warrior->getInTeam())
        {
            throw runtime_error("in the team");
        }
        if (this->getVector().size() == 10)
        {
            throw runtime_error("cant add the  size is 10");
        }
        if (new_warrior == nullptr)
        {
            throw runtime_error("cant add this warrior");
        }
        else
        {
            group=this->getVector();
            group.push_back(new_warrior);
            new_warrior->setInTeam(true);
            this->setVector(group);
           
        }
        

    }
  
};