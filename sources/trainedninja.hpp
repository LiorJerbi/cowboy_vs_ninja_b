#pragma once

#include "ninja.hpp"
#include <string>
namespace ariel{

class TrainedNinja: public Ninja{
    public:
        TrainedNinja(const std::string& name,Point spot);
        void move(Character *enemy) override;
};

}