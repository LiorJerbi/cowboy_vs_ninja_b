#include "Team.hpp"
#include <iostream>
#define MAX_SQUAD_SIZE 10

using namespace ariel;
using namespace std;

Team::Team(Character* leader){
    if(leader->isAppointed())
        throw invalid_argument("Leader already appointed to another team!");
    else{
        
        _leader = leader;
        add(_leader);
        _leader->setAppointed(true);
    }
}   

void Team::changeLeader(){
    if(_leader->isAlive()) return;
    Character* newlead = nullptr;
    double tmpdist = INT16_MAX;
    for(Character* member : _squad){
        if(member->isAlive() && member != _leader){
            if(Cowboy* cowboy = dynamic_cast<Cowboy*>(member)){     //member is type of Cowboy
                if(_leader->distance(member) < tmpdist){
                    tmpdist = _leader->distance(member);
                    newlead = member;
                }
            }
        }
    }
    for(Character* member : _squad){
        if(member->isAlive() && member != _leader){
            if(Ninja* ninja = dynamic_cast<Ninja*>(member)){     //member is type of Ninja
                if(_leader->distance(member) < tmpdist){
                    tmpdist = _leader->distance(member);
                    newlead = member;
                }
            }
        }
    }
    _leader = newlead;
}
Character* Team::getVictim(const Team* att_team) const{
    Character* victim = nullptr;
    double vicdist = INT16_MAX;
    for(Character* member : att_team->_squad){      // find closest enemy to the attacking leader
        if(member->isAlive() && _leader->distance(member) < vicdist){
            if(Cowboy* cowboy = dynamic_cast<Cowboy*>(member)){     //member is type of Cowboy
                vicdist = _leader->distance(member);
                victim = member;
            }
        }
    }
    for(Character* member : att_team->_squad){
        if(member->isAlive() && _leader->distance(member) < vicdist){
            if(Ninja* ninja = dynamic_cast<Ninja*>(member)){     //member is type of Ninja
                vicdist = _leader->distance(member);
                victim = member;
            }
        }
    }
    return victim;
}
Team& Team::operator=(const Team& other) {
    if (this == &other) {
        return *this;
    }
    delete _leader;
    _leader = other._leader;
    for (const auto& member : _squad) {
        delete member;
    }
    _squad.clear();
    for (const auto& member : other._squad) {
        _squad.push_back(member);
    }
    return *this;
}

void Team::add(Character* member){
    if(_squad.size() == MAX_SQUAD_SIZE) throw runtime_error("Squad maximum size is 10!");
    if(member->isAppointed()) throw runtime_error("Already appointed to another team!");

    _squad.push_back(member);
    member->setAppointed(true);
}
void Team::attack(Team* enmy_team){
    if(enmy_team == nullptr || enmy_team == this) throw runtime_error("Not valid enemy team!");
    if(enmy_team->stillAlive() == 0) throw runtime_error("Enemy team already dead!");
    if(!(enmy_team->_leader->isAlive())) enmy_team->changeLeader();     //if attacked leader is dead switch to the closest live enemy

    Character* victim = getVictim(enmy_team);           //get victim who is closest to the attacking leader

    for(Character* member : _squad){
        if(member->isAlive()){
            if(Cowboy* cowboy = dynamic_cast<Cowboy*>(member)){     //member is type of Cowboy
                
                if(cowboy->hasboolets()) cowboy->shoot(victim);
                else cowboy->reload();

                if(!(victim->isAlive())){       // if victim is dead choose another victim.
                    victim = getVictim(enmy_team);
                    if(victim == nullptr) return;       //if enemy team dead.
                }
            }
        }
    }
    for(Character* member : _squad){
        if(member->isAlive()){
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
int Team::stillAlive() const{
    int alive = 0;
    for(Character* member : _squad){
        if(member->isAlive()) alive++;
    }
    return alive;
}
void Team::print() const{
    
    for(Character* member : _squad){
        if(Cowboy* cowboy = dynamic_cast<Cowboy*>(member)){     //member is type of Cowboy
            cout << cowboy->print() << endl;
        }
    }
    for(Character* member : _squad){
        if(Ninja* ninja = dynamic_cast<Ninja*>(member)){     //member is type of Ninja
            cout << ninja->print() << endl;
        }
    }
}
std::vector<Character*> Team::getSquad() const{
    return _squad;
}
Character* Team::getLeader() const{
    return _leader;
}
void Team::setLeader(Character* newlead){
    _leader = newlead;
}
Team::~Team(){
    delete _leader; // Delete the leader character
    _leader = nullptr;
    for (Character* member : _squad) {
        delete member; // Delete each member character in the squad
    }
    _squad.clear();

}