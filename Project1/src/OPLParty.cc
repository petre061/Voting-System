// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#include "OPLParty.h"
#include <iostream>
#include <string>
#include <sstream>

OPLParty::OPLParty(const std::string& name) {
  pname = name;
}

uint64_t OPLParty::get_tally() {
  return candidates.size();
}
std::string OPLParty::log() const {
  stringstream output;
  output << "OPL Party " << pname << " : ["
  for(int i = 0; i < candidates.size(); i++) {
    // For all OPLCandidate objects attributed to specific OPLParty:
        for(int j = 0; j < candidates.at(i)->get_tally(); j++) {
          // For all OPLBallot objects attributed to specific OPLCandidate:
          output << candidates.at(j)->log() << ",";
          // Display the ballot ID and choice for each OPLBallot for each candidate in the party
    }   
    output << "]";
    return output.str();
}

// Creating / adding to candidates DS done in OPLElection class?