#pragma once

#include "Ninja.hpp"
#include "Character.hpp"
#include <string>
namespace ariel{

class OldNinja: public Ninja{
    public:
        OldNinja(const std::string& name,Point spot);
        void move(Character *enemy) override;
};

}