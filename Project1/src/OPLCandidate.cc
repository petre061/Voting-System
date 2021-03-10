<<<<<<< HEAD
#include "OPLCandidate.h"
#include <iostream>
#include <sstream>

OPLCandidate::OPLCandidate(const std::string& candidate) {
    name = candidate;
}

void OPLCandidate::add_ballot(OPLBallot new_ballot) {
    ballots.push_back(new_ballot);
    return;
}

uint8_t OPLCandidate::get_tally() {
    return ballots.size();
}

std::string OPLCandidate::log() { // log of all ballots in candidate's category by ids
    std::stringstream output;
    output << "Candidate : ballots =[";
    for(int i = 0; i < ballots.size(); i++) {
        output << ballots.at(i)->get_id() << ",";
    }
    output << "]";
    return output.str();
=======
// TODO(Alex, Peter): Implement line parsing

#include "OPLCandidate.h"

OPLCandidate::OPLCandidate(const std::string& candidate_name)
    : name(candidate_name) {
  // TODO: write this class
}
std::string OPLCandidate::log() const {
  // TODO:
>>>>>>> e71830705aaeaf562d0db4d202a6a32662c460e6
}