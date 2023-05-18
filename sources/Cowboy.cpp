#include "Cowboy.hpp"
#include "iostream"

using namespace ariel;
using namespace std;


Cowboy::Cowboy(const std::string& name,Point spot):Character(name,spot,110),_bullet_amount(6){};

void Cowboy::shoot(Character* enemy){
    if(enemy->getHp() <= 0) throw runtime_error("Enemy already dead!");
    if(getHp() <= 0) throw runtime_error("Cowboy is dead!");
    if(enemy == this) throw runtime_error("Cannot shoot self!");
    if(hasboolets()){
        _bullet_amount--;
        enemy->hit(10);
    }
    
}
bool Cowboy::hasboolets() const{
    return (_bullet_amount>0) ? true : false;
}

void Cowboy::reload(){
    if(getHp() <= 0) throw runtime_error("Cowboy is dead!");
    _bullet_amount=6;
}
int Cowboy::getBullAmount() const{
    return _bullet_amount;
}
string Cowboy::print() const{
    string ans = "C: ";
    if(getHp()>0){
        ans += getName() + " HP:" + to_string(getHp()) + " Location:" + getLocation().print();
    }
    else{
        ans += "("+getName() + ") Location:" + getLocation().print();
    }
    return ans;
}