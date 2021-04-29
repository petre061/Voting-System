// // Copyright 2021, CSCI 5801 Spring 2021 Team 20
// /**
//  * @file POElection.cc
//  * @author Andrew Petrescu (petre061@umn.edu)
//  * @brief This file implementes the PO Party class.
//  * @version 1.0
//  * @date 2021-04-28
//  *
//  * @copyright Copyright (c) 2021
//  *
//  */

// #include "POParty.h"
// #include "TieBreaker.h"
// #include <iostream>
// #include <string>
// #include <sstream>
// #include <map>
// #include <algorithm>
// #include <queue>

// POParty::POParty(const std::string& name) {
//     pname = name;
// }

// uint64_t POParty::get_tally() {
//     uint64_t tally = 0;
//     // Iterate through the length of the list of candidates attributed to the POParty instance, and add their tally() returns to a total party tally
//     for (int i = 0; i < candidates.size(); i++) {
//         tally += candidates.at(i)->get_tally();
//     }
//     return tally;
// }

// void POParty::add_candidate(POCandidate* new_candidate) {
//     // Add a new candidate to the POParty's list of attributed candidates
//     candidates.push_back(new_candidate);
//     return;
// }

// std::string POParty::log() const {
//     std::stringstream output;
//     output << "PO Party " << pname << ": [";
//     for (int i = 0; i < candidates.size(); i++) {
//         // For all POCandidate objects attributed to specific POParty:
//         output << candidates.at(i)->log() << ",";
//         // Display the ballot ID and choice for each POBallot for each candidate in the party   
//     }
//     output << "]";
//     return output.str();
// }

// std::string POParty::get_name() {
//     return pname;
// }

// // Return an ordered list of the highest tally-getting candidates within a given party, the length of the list being equivalent to the number of seats awarded to said party
// std::vector<std::string> POParty::get_top_n_candidate_names(int n) {
//     // duplicate the list of POCandidates attributed to party
//     std::vector<POCandidate*> candidate_list = get_candidates();
//     std::vector<std::string> result;
//     int seats = n;
//     if (seats > candidate_list.size()) {
//         throw std::invalid_argument("Request of candidates is larger than number of candidates associated with party");
//     }
//     // As long as there is at least one candidate attributed to the party - will iterate until none are in duplicate list
//     while (candidate_list.size() > 0) {
//         // So long as there are > 0 seats to allocate still:
//         if (seats > 0) {
//             // For each seat left to allocate, find max tally and index of candidate with said tally
//             int tally = 0;
//             int index = 255;
//             for (int i = 0; i < candidate_list.size(); i++) {
//                 if (candidate_list.at(i)->get_tally() > tally) {
//                     tally = candidate_list.at(i)->get_tally();
//                     index = i;
//                 }
//                 // Tie-break between the two with the same tally
//                 if (candidate_list.at(i)->get_tally() == tally) {
//                     if (TieBreaker::resolve_tie(2) == 1) {
//                         tally = candidate_list.at(i)->get_tally();
//                         index = i;
//                     }
//                 }
//             }
//             // add next highest candidate to result vector, and erase said candidate from the list being iterated through
//             result.push_back(candidate_list.at(index)->get_name());
//             std::vector<POCandidate*>::iterator i = candidate_list.begin() + index;
//             candidate_list.erase(i);
//             seats--;
//         }
//         else {
//             break;
//         }
//     }

//     return result;
// }

// std::vector<POCandidate*> POParty::get_candidates() {
//     return candidates;
// }
// // Creating / adding to candidates DS done in POElection class?