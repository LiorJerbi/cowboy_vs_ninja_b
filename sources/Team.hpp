#pragma once

#include <vector>
#include "Character.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"

namespace ariel{

    class Team{

        // protected:
        //     Character *_leader;
        //     std::vector<Character*> _squad;
        private:
            Character *_leader;
            std::vector<Character*> _squad;

            
            virtual Character* getVictim(const Team* att_team) const;          
        public:
            Team(Character* leader);
            Team(const Team& other) = delete;
            Team& operator=(const Team& other);
            void add(Character* member);
            virtual void attack(Team* enmy_team);
            int stillAlive() const;
            std::vector<Character*> getSquad() const;
            Character* getLeader() const;
            void setLeader(Character* newlead);
            virtual void changeLeader();
            virtual void print() const;
            virtual ~Team();
            Team(Team&& other) = delete;
            Team& operator=(Team&& other) = delete;
    };


}