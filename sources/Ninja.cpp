#include "Character.hpp"
#include "Ninja.hpp"
using namespace std;
namespace ariel
{
    Ninja::Ninja()
    {
    }
    Ninja::Ninja(string name, const Point &location) : Character(name, location)
    {
    }
    void Ninja::move(Character *enemy)
    {
        if (!this->isAlive())
        {
            throw runtime_error("the character is dead");
        }
        if (!enemy->isAlive())
        {
            throw runtime_error("the Enemy is dead");
        }
        else
        {
            this->setLocation(Point::moveTowards(this->getLocation(), enemy->getLocation(), this->speed));
        }
    }
    void Ninja::slash(Character *enemy)
    {
        if (enemy == this)
        {
            throw runtime_error("cant kill himself");
        }
        else if (!this->isAlive())
        {
            throw runtime_error("the character is dead");
        }
        else if (!enemy->isAlive())
        {
            throw runtime_error("the Enemy is dead");
        }
        else if (this->getLocation().distance(enemy->getLocation()) < 1)
        {
            enemy->hit(40);
        }
    }
    void Ninja::setSpeed(int s)
    {
        this->speed = s;
    }
    int Ninja::getSpeed()
    {
        return this->speed;
    }
    void Ninja::attack(Character *victim)
    {
        double distance = this->getLocation().distance(victim->getLocation()); 
        if (victim->isAlive() && this->isAlive())
        {
            if ((distance < 1) && this->isAlive())
            {
                this->slash(victim);
            }
            else
            {
                this->move(victim);
            }
        }
    }

};