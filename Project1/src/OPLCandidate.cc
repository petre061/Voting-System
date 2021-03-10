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
    output << "Candidate << " << name << " : ballots =[";
    for(int i = 0; i < ballots.size(); i++) {
        output << ballots.at(i)->log() << ",";
    }
    output << "]";
    return output.str();
}