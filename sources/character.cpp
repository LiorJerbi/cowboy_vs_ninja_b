#include "character.hpp"


using namespace ariel;
using namespace std;

Character::Character(const string& name,Point spot,int hitpoints):_name(name),_spot(spot),_hitpoints(hitpoints){
}
Character::Character(const Character &other):_name(other._name),_spot(other._spot),_hitpoints(other._hitpoints){
}
Character& Character::operator=(const Character& other){
    if (this == &other) {
        return *this;
    }
    _name = other._name;
    _spot = other._spot;
    _hitpoints = other._hitpoints;
    return *this;
}
bool Character::isAlive() const{
    return (_hitpoints>0) ? true : false;
}
double Character::distance(Character *other) const{
    return _spot.distance(other->_spot);
}
void Character::hit(int dmg){
    if(_hitpoints>0){
       _hitpoints-=dmg; 
    }  
}
int Character::getHp() const{
    return _hitpoints;
}
string Character::getName() const{
    return _name;
}
Point Character::getLocation() const{
    return _spot;
}
Character::~Character(){

}
