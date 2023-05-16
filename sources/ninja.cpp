#include "ninja.hpp"

using namespace ariel;
using namespace std;

Ninja::Ninja(const string& name,Point spot,int hitpoints, int speed):Character(name,spot,hitpoints),_speed(speed){
}
void Ninja::slash(Character *enemy){

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