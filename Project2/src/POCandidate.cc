// /**
//  * @file POCandidate.cc
//  * @author Andrew Petrescu (petre061@umn.edu)
//  * @brief This file implementes the PO Candidate class.
//  * @version 1.0
//  * @date 2021-04-25
//  *
//  * @copyright Copyright (c) 2021
//  *
//  */

// #include "POCandidate.h"
// #include <iostream>
// #include <sstream>
// #include <string>
// #include <queue>

// POCandidate::POCandidate(const std::string& candidate) {
//     name = candidate;
// }

// void POCandidate::add_ballot(POBallot new_ballot) {
//     // Adds new ballot to the POCandidate instance's set of ballots
//     ballots.push(new_ballot);
//     return;
// }

// uint64_t POCandidate::get_tally() {
//     // Returns total amount of POBallot objects attributed to this POCandidate
//     return ballots.size();
// }

// std::string POCandidate::log() const { // log of all ballots in candidate's category by ids
//     // Create stringstream object to write log info to
//     std::stringstream output;
//     // Create new POBallot queue and copy ballots to it
//     std::queue<POBallot> temp = ballots;
//     output << "Candidate " << name << ": ballots =[";
//     // While the new POBallot queue is not empty, output the log() method of each element to output, and pop it off the queue
//     while (!temp.empty()) {
//         output << temp.front().log() << ",";
//         temp.pop();
//     }
//     output << "]";
//     return output.str();
// }

// const std::string& POCandidate::get_name() const {
//     // Return a constant reference to name
//     return name;
// }
