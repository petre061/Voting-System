
// Copyright CSCI 5801 Spring 2021 Team 20

#include "OPLElection.h"
#include "OPLCandidate.h"
#include "OPLParty.h"

#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>

OPLElection::OPLElection(std::string filename) : Election("OPL", filename) {
  std::string line, name, party;
  std::map<std::string, int> p_idx; // used to map the parties to their indexes in the vector
  int p_idx_count = 0; // map index counter
  for (int i = 0; i < 5; i++){
    getline(ballot_file, line);
    if (i < 2) {
      continue;
    } else if (i == 2) {
      // TODO: parse candidates/parties
      // format line
      line.erase(std::remove(line.begin(), line.end(), '['), line.end());
      line.erase(std::remove(line.begin(), line.end(), ']'), line.end());
      line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

      // parse information and create/assign objects
      std::istringstream ss(line);
      while (getline(ss, name, ',')){
        OPLCandidate* temp = new OPLCandidate(name);
        candidates.push_back(temp);
        getline(ss, party, ',');

        // adding first party and candidate
        if (parties.size() == 0) {
          parties.push_back(OPLParty(party));
          parties.back().add_candidate(temp);
          p_idx[party] = p_idx_count++;

          // if the party exists add candidate there
        } else if (p_idx.find(party) != p_idx.end()){
          parties.at(p_idx.find(party)->second).add_candidate(temp);

          // if the party does not exist but they are a unique independent then add to independent 
        } else if (p_idx.find(party) == p_idx.end() && party.compare("D") != 0 || party.compare("R") != 0 || party.compare("I") != 0) {

          // if independent doesn't exist yet then add it 
          if (p_idx.find("I") == p_idx.end()) {
            parties.push_back(OPLParty("I"));
            parties.back().add_candidate(temp);
            p_idx["I"] = p_idx_count++;
          }

          // if independent already exists then add to exisiting independent party
          else {
            parties.at(p_idx.find("I")->second).add_candidate(temp);
          }

          // party does not exist yet so add
        } else {
          parties.push_back(OPLParty(party));
          parties.back().add_candidate(temp);
          p_idx[party] = p_idx_count++;
        }
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
  int lineNum = 0, candidate_idx = 0;
  std::string line, index;
  while (getline(ballot_file, line)) {
    ++lineNum;
    if (lineNum < 6) {
      continue;
    } else {
      // format ballot line and add ballot to specified candidate index
      line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
      std::istringstream ss(line);
      while(getline(ss, index, ',')) {
        if(index.length() == 0) {
          candidate_idx++;
        } else {
          break;
        }
      }
      candidates.at(candidate_idx)->add_ballot(OPLBallot(line));
      candidate_idx = 0;
    }
  }
  // We can close ballot file here since we are probably done with it.
  // otherwise it will be closed in the destructor of Election
  ballot_file.close();
}

void OPLElection::assign_seats() {
  // TODO: assign seats to party/candidate
  std::vector<int> remainders(parties.size());
  std::map<std::string, int> party_seats;
  // determine quota
  int quota = total_ballots / num_seats;
  // assign initial seats to parties
  for(int i = 0; i < parties.size(); i++){
    // TODO: assign initial seats
  }
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