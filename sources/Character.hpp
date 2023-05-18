#pragma once
#include "point.hpp"
#include <string>
namespace ariel{

class Character{

    // protected:      //only accessiable by subclasses
    //     Point _spot;
    //     int _hitpoints;
    //     std::string _name;
    private:
        Point _spot;
        int _hitpoints;
        std::string _name;
        bool _appointed;
    public:
        Character(const std::string &name,Point spot,int hitpoints);
        Character(const Character &other);
        Character& operator=(const Character &other);
        bool isAlive() const;
        double distance(Character *other) const;
        void hit(int dmg);
        int getHp() const;
        bool isAppointed() const;
        void setAppointed(bool mod);
        std::string getName() const;
        Point getLocation() const;
        void setLocation(Point& newp);
        virtual std::string print() const = 0;
        Character(Character&& other) = delete;
        Character& operator=(Character&& other) = delete;

        virtual ~Character() = default;

};

}