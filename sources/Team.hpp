#ifndef TEAM_HPP
#define TEAM_HPP
#include <iostream>
#include <vector>
#include <memory>
#include "Point.hpp"
#include "Ninja.hpp"
#include "Character.hpp"
#include "OldNinja.hpp"
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
using namespace std;
namespace ariel
{
    class Team
    {
    private:
        Character *leader;
        std::vector<Character *> group_Warriors;

    public:
        Team();
        Team(Character *);
        void add(Character *);
        virtual void attack(Team *);
        int stillAlive();
        virtual void print();
        Character *getLeader();
        void setLeader(Character *);
        Character *choose_Warriors_formEnemy(Team *);
        void Found_leader();
        void sortTeam();
        void setVector(vector<Character *>);
        vector<Character *> getVector();
        void attackCowboy(Team* enemy, Character* victim);
        void attackNinja(Team* enemy, Character* victim); 
    };

};
#endif