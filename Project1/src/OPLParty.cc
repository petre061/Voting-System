// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#include "OPLParty.h"
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

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
}

std::string OPLParty::get_name(){
  return pname;
}

std::vector<std::string> OPLParty::get_top_n_candidate_names(int n) {
  std::map<int, std::string> names;
  std::vector<int> totals;
  std::vector<std::string> result;
  for(int i = 0; i < candidates.size(); i++) {
    names[candidates.at(i)->get_tally()] = candidates.at(i)->get_name();
    totals.push_back(candidates.at(i)->get_tally());
  }
  for(int i = 0; i < n; i++) {
    auto highest_tally = std::max_element(std::begin(totals), std::end(totals));
    int index = std::distance(std::begin(totals), highest_tally);
    result.push_back(names[*highest_tally]);
    totals.at(index) = 0;
  }

  return result; 
}



// Creating / adding to candidates DS done in OPLElection class?