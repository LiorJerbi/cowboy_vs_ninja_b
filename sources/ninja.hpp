#pragma once

#include "character.hpp"
#include <string>
namespace ariel{

class Ninja: public Character{
    // protected:
    //     int _speed;
    private:
        int _speed;
    public:
        Ninja(const std::string& name,Point spot,int hitpoints, int speed);
        virtual void move(Character *enemy) = 0;
        void slash(Character *enemy);
        std::string print() const override;
        

};

}