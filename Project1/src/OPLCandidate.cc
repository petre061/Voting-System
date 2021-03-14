#include "OPLCandidate.h"
#include <iostream>
#include <sstream>
#include <string>
#include <queue>

OPLCandidate::OPLCandidate(const std::string& candidate) {
    name = candidate;
}

void OPLCandidate::add_ballot(OPLBallot new_ballot) {
    // Adds new ballot to the OPLCandidate instance's set of ballots
    ballots.push(new_ballot);
    return;
}

uint64_t OPLCandidate::get_tally() {
    // Returns total amount of OPLBallot objects attributed to this OPLCandidate
    return ballots.size();
}

std::string OPLCandidate::log() const { // log of all ballots in candidate's category by ids
    // Create stringstream object to write log info to
    std::stringstream output;
    // Create new OPLBallot queue and copy ballots to it
    std::queue<OPLBallot> temp = ballots;
    output << "Candidate << " << name << " : ballots =[";
    // While the new OPLBallot queue is not empty, output the log() method of each element to output, and pop it off the queue
    while (!temp.empty()) {
        output << temp.front().log() << ",";
        temp.pop();
    }
    output << "]";
    return output.str();
}

const std::string& OPLCandidate::get_name() const {
  // Return a constant reference to name
  return name;
}
