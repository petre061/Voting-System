
// Copyright CSCI 5801 Spring 2021 Team 20

#include "OPLElection.h"

#include <fstream>
#include <string>

OPLElection::OPLElection(std::string filename) : Election("IR", filename) {
  // TODO: should initialize total_ballots here
}

void OPLElection::parse_ballots() {
  // TODO: finish parse ballots

  // File is already open from constructor of Election
  int lineNum = 0;
  std::string line;
  while (getline(ballot_file, line)) {
    ++lineNum;
    if (lineNum == 1) {
      type = line;
    } else if (lineNum == 2) {
      // candidates.resize(std::stoi(line));
    } else if (lineNum == 3) {
      // TODO: parse candidate line and populate candidate and party vectors
    } else if (lineNum == 4) {
      num_seats = std::stoi(line);
    } else if (lineNum == 5) {
      total_ballots = std::stoi(line);
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
}

void OPLElection::announce_results() {
  // TODO: display winner, vote percentages, other info to screen
}

int OPLElection::run() {
  // TODO: driver function for OPL elections

  // parse ballots
  // assign first round of seats to parties
  // rank parties by remaining votes
  // allocate seats in order of highest remaining votes
  // assign candidates to seats based on number of votes (will probably need
  // another function for this)
}

std::string OPLElection::log() const {
  // TODO: log OPL election movements/information
}