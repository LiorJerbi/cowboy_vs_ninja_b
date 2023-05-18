#include "Ninja.hpp"
#include <iostream>

using namespace ariel;
using namespace std;

Ninja::Ninja(const string& name,Point spot,int hitpoints, int speed):Character(name,spot,hitpoints),_speed(speed){
}
void Ninja::slash(Character *enemy){
    if(enemy->getHp() <= 0) throw runtime_error("Enemy already dead!");
    if(getHp() <= 0) throw runtime_error("Ninja is dead!");    
    if(enemy == this) throw runtime_error("Cannot slash self!");
    if(distance(enemy) < 1.0)
        enemy->hit(40);
}
string Ninja::print() const{
    string ans = "N: ";
    if(getHp()>0){
        ans += getName() + " " + to_string(getHp()) + " " + getLocation().print();
    }
    else{
        ans += "("+getName() + ") " + getLocation().print();
    }
    return ans;
}
int Ninja::getSpeed() const{
    return _speed;
}