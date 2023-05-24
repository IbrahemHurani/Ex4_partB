#include"OldNinja.hpp"
#include"Ninja.hpp"
using namespace std;
namespace ariel{
    OldNinja::OldNinja(){

    }
    OldNinja::OldNinja(string name,const Point &location):Ninja(name,location){
        this->setSpeed(8);
        this->setHit(150);
        this->setType("N");
        

    }
   


};