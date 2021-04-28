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

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>

#include "TieBreaker.h"

OPLParty::OPLParty(const std::string& name) { pname = name; }

uint64_t OPLParty::get_tally() {
  uint64_t tally = 0;
  // Iterate through the length of the list of candidates attributed to the
  // OPLParty instance, and add their tally() returns to a total party tally
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
  for (int i = 0; i < candidates.size(); i++) {
    // For all OPLCandidate objects attributed to specific OPLParty:
    output << candidates.at(i)->log() << ",";
    // Display the ballot ID and choice for each OPLBallot for each candidate in
    // the party
  }
  output << "]";
  return output.str();
}

std::string OPLParty::get_name() { return pname; }

bool candidate_sorter(OPLCandidate* a, OPLCandidate* b) {
  return a->get_tally() < b->get_tally();
}
// Return an ordered list of the highest tally-getting candidates within a given
// party, the length of the list being equivalent to the number of seats awarded
// to said party
std::vector<std::string> OPLParty::get_top_n_candidate_names(uint64_t n) const {
  // duplicate the list of OPLCandidates attributed to party
  std::vector<OPLCandidate*> candidate_list = get_candidates();
  std::map<uint64_t, std::vector<OPLCandidate*>> unique_tallies;

  std::vector<std::string> result;

  // Sort the candidates into a list
  std::sort(candidate_list.begin(), candidate_list.end(), candidate_sorter);

  // Sort the candidates into partitions of tallies
  for (auto can : candidate_list) {
    unique_tallies[can->get_tally()].push_back(can);
  }

  for (auto& tally : unique_tallies) {
    if (tally.second.size() < n) {
      // Add all the candidates in a partition if there are enough seats left
      for (auto& can : tally.second) {
        result.push_back(can->get_name());
      }
      n -= tally.second.size();
    } else {
      // Allocate the remaining seats to tie winners
      while (n > 0) {
        // Determine a winner
        size_t winner = TieBreaker::resolve_tie(tally.second.size());
        // Put them into the result
        result.push_back(tally.second[winner]->get_name());
        // Remove them from the partition
        tally.second.erase(tally.second.begin() + winner);
        // Decrement the number of remaining seats
        n--;
      }
    }
  }

  return result;
}

const std::vector<OPLCandidate*>& OPLParty::get_candidates() const {
  return candidates;
}
// Creating / adding to candidates DS done in OPLElection class?