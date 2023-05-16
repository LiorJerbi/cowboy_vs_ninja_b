#include "Team.hpp"

using namespace ariel;
using namespace std;

Team::Team(Character* leader):_leader(leader){}
Team::Team(const Team& other) : _leader(other._leader) {
    for (const auto member : other._squad) {
        _squad.push_back(member);
    }
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

}
void Team::attack(Team* enmy_team){

}
int Team::stillAlive() const{
    return 0;
}
void Team::print() const{
    
}
Team::~Team(){
    // if(_leader != nullptr)
    // delete _leader;
    // for (const auto& member : _squad) {
    //     if(member != nullptr)
    //     delete member;
    // }
    // _squad.clear();
}