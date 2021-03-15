// Copyright CSCI 5801 Spring 2021 Team 20
/**
 * @file OPLElection.cc
 * @author Nikhil Srikanth (srika018@umn.edu)
 * @author Peter Linden (linde764@umn.edu)
 * @author Alex Bohm (bohm0080@umn.edu)
 * @author Andrew Petrescu (petre061@umn.edu)
 * @brief This file declares the OPL Election class.
 * @version 1.0
 * @date 2021-03-14
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef OPLELECTION_H_
#define OPLELECTION_H_

#include <string>
#include <map>

#include "Election.h"
#include "OPLCandidate.h"
#include "OPLParty.h"
#include "OPLBallot.h"
#include "TieBreaker.h"


/**
 * @brief
 */
class OPLElection : public Election {
    private:
        /**
        * @brief List that stores all indicies of a max tally, used for tie breaker
        */
        std::vector<int> max_indicies;
        /**
        * @brief List that stores pointers of all candidates
        */
        std::vector<OPLCandidate*> candidates;
        /**
        * @brief List that stores all parties 
        */ 
        std::vector<OPLParty> parties;
        /**
        * @brief Map used for assigning seats won to parties
        */
        std::map<std::string, int> party_seats;
        /**
        * @brief Map used for assigning a list of candidates to their party
        */
        std::map<std::string, std::vector<std::string>> party_candidates;
        /**
        * @brief Integer that holds the total number of seats avaible in the election
        */
        uint16_t num_seats = 0;
        /**
        * @brief Parse the ballots from the file
        */
        void parse_ballots();
        /**
        * @brief Assign seats to parties and candidates to seats
        */
        void assign_seats();
        /**
        * @brief Prints to screen, media file, and audit log all necessary information about the results of the election
        */
        void announce_results();
        /**
        * @brief Finds all instances of the highest tally in a given list of candidate tallies
        * 
        * @param tallies A list of candidate tallies
        * @param max The max tally number we are searching for in the list
        */
        void find_max_values(std::vector<int> tallies, int max);

    public:
        /**
        * @brief Constructor for an OPL Election object
        */
        explicit OPLElection(std::string filename);
        /**
        * @brief Run an OPL Election
        */
        int run();
        /**
        * @brief Prints to screen, media file, and audit log all necessary information about the results of the election
        */
        std::string log() const override;
};

#endif