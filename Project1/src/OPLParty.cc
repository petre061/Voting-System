// Copyright 2021, CSCI 5801 Spring 2021 Team 20
/**
 * @file OPLElection.cc
 * @author Peter Linden (linde764@umn.edu)
 * @author Nikhil Srikanth (srika018@umn.edu)
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file implementes the OPL Party class.
 * @version 1.0
 * @date 2021-03-14
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "OPLParty.h"
#include "TieBreaker.h"
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <queue>

OPLParty::OPLParty(const std::string& name) {
  pname = name;
}

uint64_t OPLParty::get_tally() {
  uint64_t tally =0;
  // Iterate through the length of the list of candidates attributed to the OPLParty instance, and add their tally() returns to a total party tally
  for (int i = 0; i < candidates.size(); i++) {
    tally += candidates.at(i)->get_tally();
  }
  return tally;
}

void OPLParty::add_candidate(OPLCandidate* new_candidate) {
  // Add a new candidate to the OPLParty's list of attributed candidates
  candidates.push_back(new_candidate);
  return;
}

std::string OPLParty::log() const {
  std::stringstream output;
  output << "OPL Party " << pname << ": [";
  for(int i = 0; i < candidates.size(); i++) {
    // For all OPLCandidate objects attributed to specific OPLParty:
    output << candidates.at(i)->log() << ",";
    // Display the ballot ID and choice for each OPLBallot for each candidate in the party   
  }
  output << "]";
  return output.str();
}

std::string OPLParty::get_name(){
  return pname;
}

std::vector<std::string> OPLParty::get_top_n_candidate_names(int n) {
  std::vector<OPLCandidate*> candidate_list = get_candidates();
  std::vector<std::string> result;
  int seats = n;
  if(seats > candidate_list.size()) {
    throw std::invalid_argument("Request of candidates is larger than number of candidates associated with party");
  }
  while(candidate_list.size() > 0) {
    if(seats > 0) {
      int tally = 0;
      int index = 255;
      for(int i = 0; i < candidate_list.size(); i++) {
        if(candidate_list.at(i)->get_tally() > tally) {
          tally = candidate_list.at(i)->get_tally();
          index = i;
        }
        if(candidate_list.at(i)->get_tally() == tally) {
          //TieBreaker t = new T
          if(TieBreaker::resolve_tie(2) == 1) {
            tally = candidate_list.at(i)->get_tally();
            index = i;
          }
        }        
      }
      result.push_back(candidate_list.at(index)->get_name());
      std::vector<OPLCandidate*>::iterator i = candidate_list.begin() + index;
      candidate_list.erase(i);
      seats --;
    }
    else {
      break;
    }
  }

  return result;
}

std::vector<OPLCandidate*> OPLParty::get_candidates() {
  return candidates;
}
// Creating / adding to candidates DS done in OPLElection class?