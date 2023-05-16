#include "cowboy.hpp"

using namespace ariel;
using namespace std;


Cowboy::Cowboy(const std::string& name,Point spot):Character(name,spot,110),_bullet_amount(6){};

void Cowboy::shoot(Character* enemy){
    if(getHp() <=0 && hasboolets()){
        _bullet_amount--;
        enemy->hit(10);
    }
    
}
bool Cowboy::hasboolets() const{
    return (_bullet_amount>0) ? true : false;
}

void Cowboy::reload(){
    _bullet_amount=6;
}
int Cowboy::getBullAmount() const{
    return _bullet_amount;
}
string Cowboy::print() const{
    string ans = "C: ";
    if(getHp()>0){
        ans += getName() + " " + to_string(getHp()) + " " + getLocation().print();
    }
    else{
        ans += "("+getName() + ") " + getLocation().print();
    }
    return ans;
}