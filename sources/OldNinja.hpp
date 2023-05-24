#ifndef OLD_NINJA_HPP
#define OLD_NINJA_HPP
#include <iostream>
#include<string.h>
#include"Point.hpp"
#include"Ninja.hpp"
using namespace std;
namespace ariel
{
    class OldNinja : public Ninja
    {
    private:
        int speed;

    public:
        OldNinja();
        OldNinja(string name ,const Point &);
        ~OldNinja() override=default;
       

    };

};

#endif