#include <iostream>
#include "Character.hpp"

using namespace std;
namespace ariel
{
    Character::Character() : Name(""), Location(Point(0, 0)), Hit(0)
    {
    }
    Character::Character(string name, const Point &location) : Name(name), Location(location)
    {
        this->inTeam=false;
    }
    string Character::getName()
    {
        return this->Name;
    }
    Point &Character::getLocation()
    {
        return this->Location;
    }
    string Character::print()
    {
        if (this->isAlive())
        {
            return "Name: " + this->getName() + ","+"Hit: "+to_string(this->Hit)+",Location " + this->Location.convert_ToString();
        }
        return " "+this->type+":("+this->getName()+")";
    }
    void Character::hit(int damage)
    {
        if(damage<0){
            throw invalid_argument("the damage is negtive");
        }
        this->Hit=this->Hit-damage;
    }
    bool Character::isAlive()
    {
        if (this->Hit > 0)
        {
            return true;
        }
        return false;
    }
    double Character::distance(const Character *other)
    {
        return this->Location.distance(other->Location);
    }
    void Character::setHit(int newHit)
    {
        this->Hit = newHit;
    }
    int Character::getHit(){
        return this->Hit;
    }
    void Character::setType(string t_type){
        this->type=t_type;
    }
    void Character::setLocation(const Point &newPoint){
        this->Location=newPoint;
    }
    string Character::getType(){
        return this->getType();
    }
    void Character::setInTeam(bool in){
        this->inTeam=in;
    }
    bool Character::getInTeam(){
        return this->inTeam;
    }
   

    
    

};
