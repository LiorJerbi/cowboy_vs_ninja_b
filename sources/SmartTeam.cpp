#include "SmartTeam.hpp"

#include <iostream>
using namespace ariel;
using namespace std;

SmartTeam::SmartTeam(Character* leader):Team(leader){
}

void SmartTeam::changeLeader(){
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
Character* SmartTeam::getVictimC(const Team* att_team) const{
    Character* victim = nullptr;
    int minhp = INT16_MAX;
    for(Character* member : att_team->getSquad()){      // find the enemy with the lowest hp alive.
        if(member->isAlive() && member->getHp() < minhp){
            minhp = member->getHp();
            victim = member;
        }
    }
    return victim;
}
Character* SmartTeam::getVictimN(const Team* att_team,Character* attacker) const{
    Character* victim = nullptr;
    double mindist = INT16_MAX;
    for(Character* member : att_team->getSquad()){      // find the enemy that is closest as possibole to attacker.
        if(member->isAlive() && attacker->distance(member) < mindist){
            mindist = attacker->distance(member);
            victim = member;
        }
    }
    return victim;
}
void SmartTeam::attack(Team* enmy_team){
    if(enmy_team == nullptr || enmy_team == this) throw invalid_argument("Not valid enemy team!");
    if(enmy_team->stillAlive() == 0) throw runtime_error("Enemy team already dead!");
    if(!(enmy_team->getLeader()->isAlive())) enmy_team->changeLeader();     //if attacked leader is dead switch to the closest live enemy
    if(!(getLeader()->isAlive())) changeLeader();

    for(Character* member : getSquad()){
        if(member->isAlive()){
            if(Cowboy* cowboy = dynamic_cast<Cowboy*>(member)){     //member is type of Cowboy
                Character* victim = getVictimC(enmy_team);       //gets the victim with lowest hp for elimniating the most enemys possibole from distance
                if(cowboy->hasboolets()) cowboy->shoot(victim);
                else cowboy->reload();
            }    
            if(Ninja* ninja = dynamic_cast<Ninja*>(member)){     //member is type of Ninja
                Character* victim = getVictimN(enmy_team,ninja);       //choose the closest victim as it gets to Ninja
                if(ninja->distance(victim) < 1.0) ninja->slash(victim);
                else ninja->move(victim);                
                if(!(victim->isAlive())){       // if victim is dead choose another victim.
                    victim = getVictimN(enmy_team,ninja);
                    if(victim == nullptr) return;       //if enemy team dead.
                }
            }
        }
    }        
}
void SmartTeam::print() const{      //prints the live members first
    cout << "Team details:" << endl;
    for(Character* member : getSquad()){
        if(member->isAlive()){
            cout << member->print() << endl;
        }
    }
    for(Character* member : getSquad()){
        if(!(member->isAlive())){
            cout << member->print() << endl;
        }
    }
}