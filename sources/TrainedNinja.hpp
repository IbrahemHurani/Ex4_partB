#ifndef Trained_HPP
#define Trained_HPP
#include <iostream>
#include <string.h>
#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "TrainedNinja.hpp"
#include"Ninja.hpp"
using namespace std;
namespace ariel
{
    class TrainedNinja : public Ninja
    {
    private:
        int speed;

    public:
        TrainedNinja();
        TrainedNinja(string name, const Point &);
        ~TrainedNinja() override=default;
        
    };

};

#endif