// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#include "OPLParty.h"
#include <iostream>
#include <string>
#include <sstream>

OPLParty::OPLParty(const std::string& name) {
  pname = name;
}

uint64_t OPLParty::get_tally() {
  uint64_t tally =0;
  for (int i = 0; i < candidates.size(); i++) {
    tally += candidates.at(i)->get_tally();
  }
  return tally;
}

void OPLParty::add_candidate(OPLCandidate* new_candidate) {
  candidates.push_back(new_candidate);
  return;
}

std::string OPLParty::log() const {
  std::stringstream output;
  output << "OPL Party " << pname << ": [";
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

std::string OPLParty::get_name(){
  return pname;
}

// Creating / adding to candidates DS done in OPLElection class?