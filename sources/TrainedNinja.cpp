#include "TrainedNinja.hpp"

using namespace ariel;
using namespace std;


TrainedNinja::TrainedNinja(const string& name,Point spot):Ninja(name,spot,120,12){};
void TrainedNinja::move(Character *enemy){
    Point tmp = Point::moveTowards(getLocation(),enemy->getLocation(),getSpeed());
    setLocation(tmp);
}