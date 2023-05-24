#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include <string.h>
#include "Point.hpp"
using namespace std;
namespace ariel
{
    class Character
    {
    private:
        Point Location;
        string Name;
        int Hit;
        string type;
        bool inTeam;

    public:
        Character(string, const Point &);
        Character();
        string getName();
        Point& getLocation();
        virtual string print();
        double distance(const Character *other);
        bool isAlive();
        void hit(int damage);
        void setHit(int );
        int getHit();
        void setType(string );
        void setLocation(const Point&);
        string getType();
        bool getInTeam();
        void setInTeam(bool );
        
        virtual ~Character()=default;

    };

}
#endif