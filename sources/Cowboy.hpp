#ifndef COWBOY_HPP
#define COWBOY_HPP

#include<iostream>
#include<string.h>
#include "Point.hpp"
#include "Character.hpp"
using namespace std;
namespace ariel{
    class Cowboy:public Character{
        private:
            int bullets;
        public:
            Cowboy();
            Cowboy(string name, const Point&);
            bool hasboolets();
            void reload();
            void shoot( Character*);
            void setBullets(int );
            int getBullets();
            void attack(Character *victim);
            ~Cowboy() override=default;





    };
};
#endif