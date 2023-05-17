#pragma once

#include "Ninja.hpp"
#include <string>
namespace ariel{

class YoungNinja: public Ninja{
    public:
        YoungNinja(const std::string &name,Point spot);
        void move(Character *enemy) override;
};

}