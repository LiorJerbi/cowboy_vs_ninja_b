#pragma once

#include "Team.hpp"

namespace ariel{

class Team2 : public Team{

    private:
        virtual Character* getVictim(const Team* att_team) const override;         
    public:
        virtual void changeLeader() override;
        Team2(Character* leader);
        void attack(Team* enmy_team) override;
        void print() const override;
};

}