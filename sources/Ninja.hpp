#ifndef _NINJA_HPP
#define _NINJA_HPP
#include <iostream>
#include<string.h>
#include"Point.hpp"
#include "Character.hpp"
using namespace std;
namespace ariel
{
    class Ninja : public Character
    {
    private:
        int speed;

    public:
        Ninja();
        Ninja(string name ,const Point &);
        void move(Character*);
        void slash(Character*);
        void setSpeed(int );
        int getSpeed();
        void attack(Character *victim);
        ~Ninja() override=default;

    };

};
#endif