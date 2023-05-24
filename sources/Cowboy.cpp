#include "Cowboy.hpp"
#include "Character.hpp"
using namespace std;
namespace ariel
{
    Cowboy::Cowboy()
    {
    }
    Cowboy::Cowboy(string name, const Point &location) : Character(name, location)
    {
        this->setType("C");
        this->setBullets(6);
        this->setHit(110);
    }
    bool Cowboy::hasboolets()
    {
        if (this->bullets > 0)
        {
            return true;
        }
        return false;
    }
    void Cowboy::reload()
    {
        if (!this->isAlive())
        {
            throw runtime_error("the character is dead can't realod ");
        }
        this->setBullets(6);
    }
    void Cowboy::shoot(Character *enemy)
    {
        if (enemy == this)
        {
            throw runtime_error("cant kill himself");
        }
        if (!enemy->isAlive())
        {
            throw runtime_error("the enemy is dead");
        }
        if (!this->isAlive())
        {
            throw runtime_error("the character is dead");
        }
        if (this->isAlive() && this->hasboolets())
        {
            enemy->hit(10);
            this->setBullets(this->bullets - 1);
        }
    }
    void Cowboy::setBullets(int bull)
    {
        this->bullets = bull;
    }
    int Cowboy::getBullets()
    {
        return this->bullets;
    }
    void Cowboy::attack(Character *victim)
    {
        if (victim->isAlive() && this->isAlive())
        {
            if (this->hasboolets())
            {
                this->shoot(victim);
            }
            else
            {
                this->reload();
            }
        }
    }

};