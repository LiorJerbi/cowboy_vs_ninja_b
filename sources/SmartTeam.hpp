#pragma once

#include "Team.hpp"

namespace ariel{

class SmartTeam : public Team{

    private:
        Character* getVictimC(const Team* att_team) const;
        Character* getVictimN(const Team* att_team,Character* attacker) const;   
    public:
        void changeLeader() override;
        SmartTeam(Character* leader);
        void attack(Team* enmy_team) override;
        void print() const override;
};

}