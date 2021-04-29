// // Copyright CSCI 5801 Spring 2021 Team 20
// /**
//  * @file POElection.h
//  * @author Andrew Petrescu (petre061@umn.edu)
//  * @brief This file declares the PO Election class.
//  * @version 1.0
//  * @date 2021-04-25
//  *
//  * @copyright Copyright (c) 2021
//  *
//  */

// #ifndef POELECTION_H_
// #define POELECTION_H_

// #include <string>
// #include <map>

// #include "Election.h"
// #include "POCandidate.h"
// #include "POParty.h"
// #include "POBallot.h"
// #include "TieBreaker.h"


//  /**
//   * @brief
//   */
// class POElection : public Election {
// private:
//     /**
//     * @brief List that stores all indicies of a max tally, used for tie breaker
//     */
//     std::vector<int> max_indicies;
//     /**
//     * @brief List that stores pointers of all candidates
//     */
//     std::vector<POCandidate*> candidates;
//     /**
//     * @brief List that stores all parties
//     */
//     std::vector<POParty> parties;
//     /**
//     * @brief Map used for assigning a list of candidates to their party
//     */
//     std::map<std::string, std::vector<std::string>> party_candidates;
//     /**
//     * @brief Parse the ballots from the file
//     */
//     void parse_ballots();
//     /**
//     * @brief Prints to screen, media file, and audit log all necessary information about the results of the election
//     */
//     void announce_results();
//     /**
//     * @brief Finds all instances of the highest tally in a given list of candidate tallies
//     *
//     * @param tallies A list of candidate tallies
//     * @param max The max tally number we are searching for in the list
//     */
//     void find_max_values(std::vector<int> tallies, int max);

// public:
//     /**
//     * @brief Constructor for an PO Election object
//     */
//     explicit POElection(std::string filename);
//     /**
//     * @brief Run an PO Election
//     */
//     int run();
//     /**
//     * @brief Prints to screen, media file, and audit log all necessary information about the results of the election
//     */
//     std::string log() const override;
// };

// #endif