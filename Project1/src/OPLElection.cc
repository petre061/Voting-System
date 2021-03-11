
// Copyright CSCI 5801 Spring 2021 Team 20

#include "OPLElection.h"
#include "OPLCandidate.h"
#include "OPLParty.h"

#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

OPLElection::OPLElection(std::string filename) : Election("OPL", filename) {
  std::string line, out, party;
  for(int i = 0; i < 5; i++){
    getline(ballot_file, line);
    if(i < 2) {
      continue;
    } else if (i == 2) {
      // TODO: parse candidates/parties
      // format line
      line.erase(std::remove(line.begin(), line.end(), '['), line.end());
      line.erase(std::remove(line.begin(), line.end(), ']'), line.end());
      line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

      // parse information and create/assign objects
      std::istringstream ss(line);
      while(getline(ss, out, ',')){
        // candidates.push_back(new OPLCandidate(out));               not sure the proper way to push a pointer here
        getline(ss, party, ',');
        // parties.push_back(new OPLParty(party));
        // parties.back().candidates.push(new OPLCandidate(out));      party's candidates inaccessible?
      }
    } else if (i == 3) {
      num_seats = std::stoi(line);
    } else if (i == 4) {
      total_ballots = std::stoi(line);
    }
  }
}

void OPLElection::parse_ballots() {
  // TODO: finish parse ballots

  // File is already open from constructor of Election
  int lineNum = 0;
  std::string line;
  while (getline(ballot_file, line)) {
    ++lineNum;
    if (lineNum < 6) {
      continue;
    } else {
      // TODO: Add ballot to candidate based on index
    }
  }
  // We can close ballot file here since we are probably done with it.
  // otherwise it will be closed in the destructor of Election
  ballot_file.close();
}

void OPLElection::assign_seats() {
  // TODO: assign seats to party/candidate

  // determine quota
  // assign initial seats to parties
  // rank parties by remaining votes
  // allocate seats in order of highest remaining votes
  // assign candidates to seats based on number of votes (will probably need
  // another function for this)
}

void OPLElection::announce_results() {
  // TODO: display winner, vote percentages, other info to screen
}

int OPLElection::run() {

  // parse ballots
  parse_ballots();
  // assign seats to parties
  assign_seats();
  // display results
  announce_results();

  return 0;
}

std::string OPLElection::log() const {
  // TODO: log OPL election movements/information
}