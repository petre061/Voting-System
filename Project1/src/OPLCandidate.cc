#include "OPLCandidate.h"
#include <iostream>
#include <sstream>
#include <string>
#include <queue>

OPLCandidate::OPLCandidate(const std::string& candidate) {
    name = candidate;
}

void OPLCandidate::add_ballot(OPLBallot new_ballot) {
    ballots.push(new_ballot);
    return;
}

uint64_t OPLCandidate::get_tally() {
    return ballots.size();
}

std::string OPLCandidate::log() const { // log of all ballots in candidate's category by ids
    std::stringstream output;
    std::queue<OPLBallot> temp = ballots;
    output << "Candidate << " << name << " : ballots =[";
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
