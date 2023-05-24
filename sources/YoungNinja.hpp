#ifndef YoungNinja_HPP
#define YoungNinja_HPP
#include <iostream>
#include <string.h> 
#include "Point.hpp"
#include "Ninja.hpp"
using namespace std;
namespace ariel
{
    class YoungNinja : public Ninja
    {
    private:
        int speed;

    public:
        YoungNinja();
        YoungNinja(string name, const Point &);
        ~YoungNinja()override=default;
    };

};

#endif