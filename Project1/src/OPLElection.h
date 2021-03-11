// Copyright CSCI 5801 Spring 2021 Team 20

#ifndef OPLELECTION_H_
#define OPLELECTION_H_

#include <string>

#include "Election.h"
#include "OPLCandidate.h"
#include "OPLParty.h"
#include "OPLBallot.h"

/**
 * @brief
 */
class OPLElection : public Election {
    private:
        std::vector<OPLCandidate*> candidates; 
        std::vector<OPLParty> parties;
        uint16_t num_seats = 0;
        void parse_ballots();
        void assign_seats();
        void announce_results();

    public:
        explicit OPLElection(std::string filename);
        int run();
        std::string log() const override;
};

#endif