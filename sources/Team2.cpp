#include "Team2.hpp"

#include <iostream>
using namespace ariel;
using namespace std;

Team2::Team2(Character* leader):Team(leader){
}
void Team2::changeLeader(){
    if(getLeader()->isAlive()) return;
    Character* newlead = nullptr;
    double tmpdist = INT16_MAX;
    for(Character* member : getSquad()){
        if(member->isAlive() && member != getLeader()){
            if(getLeader()->distance(member) < tmpdist){
                tmpdist = getLeader()->distance(member);
                newlead = member;
            }
        }
    }
    setLeader(newlead);
}
Character* Team2::getVictim(const Team* att_team) const{
    Character* victim = nullptr;
    double vicdist = INT16_MAX;
    for(Character* member : att_team->getSquad()){      // find closest enemy to the attacking leader
        if(member->isAlive() && getLeader()->distance(member) < vicdist){
            vicdist = getLeader()->distance(member);
            victim = member;   
        }
    }
    return victim;
}
void Team2::attack(Team* enmy_team){
    if(enmy_team == nullptr || enmy_team == this) throw invalid_argument("Not valid enemy team!");
    if(enmy_team->stillAlive() == 0) throw runtime_error("Enemy team already dead!");
    if(!(enmy_team->getLeader()->isAlive())) enmy_team->changeLeader();     //if attacked leader is dead switch to the closest live enemy
    if(!(getLeader()->isAlive())) changeLeader();

    Character* victim = getVictim(enmy_team);           //get victim who is closest to the attacking leader

    for(Character* member : getSquad()){
        if(member->isAlive()){
            if(Cowboy* cowboy = dynamic_cast<Cowboy*>(member)){     //member is type of Cowboy
                
                if(cowboy->hasboolets()) cowboy->shoot(victim);
                else cowboy->reload();

                if(!(victim->isAlive())){       // if victim is dead choose another victim.
                    victim = getVictim(enmy_team);
                    if(victim == nullptr) return;       //if enemy team dead.
                }
            }
            if(Ninja* ninja = dynamic_cast<Ninja*>(member)){     //member is type of Ninja
                
                if(ninja->distance(victim) < 1.0) ninja->slash(victim);
                else ninja->move(victim);

                if(!(victim->isAlive())){       // if victim is dead choose another victim.
                    victim = getVictim(enmy_team);
                    if(victim == nullptr) return;       //if enemy team dead.
                }
            }
        }
    }
}
void Team2::print() const{
    cout << "Team details:" << endl;
    for(Character* member : getSquad()){
        if(Cowboy* cowboy = dynamic_cast<Cowboy*>(member)){     //member is type of Cowboy
            cout << cowboy->print() << endl;
        }
        if(Ninja* ninja = dynamic_cast<Ninja*>(member)){     //member is type of Ninja
            cout << ninja->print() << endl;
        }
    }
}