#pragma once

#include "Team.hpp"

namespace ariel{

class SmartTeam : public Team{

    public:
        SmartTeam(Character* leader);
        void attack(Team* enmy_team) override;
        void print() const override;
};

}