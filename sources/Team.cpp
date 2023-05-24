#include <vector>
#include "Team.hpp"

using namespace std;
namespace ariel
{
    Team::Team(Character *lead) : leader(lead), group_Warriors()
    {
        if (this->leader->getInTeam())
        {
            throw runtime_error("the leader in another Team");
        }
        add(leader);
    }
    void Team::sortTeam()
    {
        vector<Character *> newTeam;
        for (auto t : this->group_Warriors)
        {

            if (dynamic_cast<Cowboy *>(t) != nullptr)
            {
                newTeam.push_back(t);
            }
        }
        for (auto k : this->group_Warriors)
        {
            if (dynamic_cast<Ninja *>(k) != nullptr)
            {
                newTeam.push_back(k);
            }
        }
        this->group_Warriors = newTeam;
    }
    void Team::add(Character *new_warrior)
    {
        if (new_warrior->getInTeam())
        {
            throw runtime_error("in the team");
        }
        if (this->group_Warriors.size() == 10)
        {
            throw runtime_error("cant add the  size is 10");
        }
        if (new_warrior == nullptr)
        {
            throw runtime_error("cant add this warrior");
        }
        else
        {
            this->group_Warriors.push_back(new_warrior);
            new_warrior->setInTeam(true);
            sortTeam();//to sort the team cowboy in the beginng and the ninja in last vector
        }
    }
    Character *Team::choose_Warriors_formEnemy(Team *enemy)//the function to choose victiom from the enemy
    {

        double Min = numeric_limits<double>::max();
        Character *choose = nullptr;
        for (auto e : enemy->group_Warriors)
        {
            if (e->isAlive() && e != nullptr)
            {
                double dis = this->leader->distance(e);
                if (Min > dis)
                {
                    Min = dis;
                    choose = e;
                }
            }
        }
        return choose;
    }
    void Team::Found_leader()//this function to found new leader 
    {
        if (this->stillAlive() == 0)
        {
            throw runtime_error("the team is dead");
        }
        Character *newleader = nullptr;
        double min = numeric_limits<double>::max();
        for (auto t : this->group_Warriors)
        {
            if (t->isAlive())
            {
                double dis = this->leader->distance(t);
                if (dis < min)
                {
                    min = dis;
                    newleader = t;
                }
            }
        }
        this->setLeader(newleader);
    }
    void Team::attackCowboy(Team *enemy, Character *victim)//this function for attack all the cowboy the victim
    {
        for (Character *w : this->group_Warriors)
        {
            if (Cowboy *cowboy = dynamic_cast<Cowboy *>(w))//check if the warrior is cowboy
            {
                if (cowboy->isAlive())
                {
                    cowboy->attack(victim);
                    if (!victim->isAlive())
                    {
                        if (enemy->stillAlive() == 0)//check if enemy is dead if not dead choose another victim
                        {
                            return;
                        }
                        else
                        {
                            victim = choose_Warriors_formEnemy(enemy);//choose new victim
                        }
                    }
                }
            }
        }
    }

    void Team::attackNinja(Team *enemies, Character *victim)
    {
        for (Character *w : this->group_Warriors)
        {
            if (Ninja *ninja = dynamic_cast<Ninja *>(w))//check the warrior is ninja 
            {
                if (ninja->isAlive())
                {
                    ninja->attack(victim);
                    if (!victim->isAlive())
                    {
                        if (enemies->stillAlive() == 0)//check if the enemy dead
                        {
                            return;
                        }
                        else
                        {
                            victim = choose_Warriors_formEnemy(enemies);
                        }
                    }
                }
            }
        }
    }

    void Team::attack(Team *enemy)
    {
        if (this->stillAlive() == 0)
        {
            throw runtime_error("The team is dead");
        }
        if (enemy == nullptr)
        {
            throw invalid_argument("ERROR !! enemy is->nullptr");
        }
        if (enemy->stillAlive() == 0)
        {
            throw runtime_error("enemy is dead");
        }

        if (!this->leader->isAlive())
        {
            Found_leader();
        }

        Character *victim = choose_Warriors_formEnemy(enemy);

        attackCowboy(enemy, victim);
        attackNinja(enemy, victim);
    }

    int Team::stillAlive()
    {
        int counter = 0;
        for (auto t : this->group_Warriors)
        {
            if (t->isAlive())
            {
                counter++;
            }
        }
        return counter;
    }
    void Team::print()
    {
        for (auto t : this->group_Warriors)
        {
            cout << t->print() << endl;
        }
    }
    Character *Team::getLeader()
    {
        return this->leader;
    }
    void Team::setLeader(Character *new_leader)
    {
        this->leader = new_leader;
    }
    void Team::setVector(vector<Character *> v)
    {
        this->group_Warriors = v;
    }
    vector<Character *> Team::getVector()
    {
        return this->group_Warriors;
    }
};