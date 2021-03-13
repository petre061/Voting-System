// Copyright CSCI 5801 Spring 2021 Team 20

#ifndef OPLELECTION_H_
#define OPLELECTION_H_

#include <string>
#include <map>

#include "Election.h"
#include "OPLCandidate.h"
#include "OPLParty.h"
#include "OPLBallot.h"
#include <TieBreaker.h>


/**
 * @brief
 */
class OPLElection : public Election {
    private:
        std::vector<int> max_indicies;
        std::vector<OPLCandidate*> candidates; 
        std::vector<OPLParty> parties;
        std::map<std::string, int> party_seats;
        std::map<std::string, std::vector<std::string>> party_candidates;
        uint16_t num_seats = 0;
        void parse_ballots();
        void assign_seats();
        void announce_results();
        void find_max_values(std::vector<int> tallies, int max);

    public:
        explicit OPLElection(std::string filename);
        int run();
        std::string log() const override;
};

#endif