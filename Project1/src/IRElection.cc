
// Copyright CSCI 5801 Spring 2021 Team 20

#include "IRElection.h"

#include <sstream>
#include <string>

IRElection::IRElection(const std::string& filename) : Election("IR", filename) {
  // TODO: should initialize total_ballots here
}

void IRElection::parse_ballots() {
  // TODO: finish parse ballots

  // File is already open from Election constructor
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
      total_ballots = std::stoi(line);
    } else {
      // TODO: store ballots in candidates (maybe assign first choices here
      // too?)
    }
  }
  // Can close here otherwise it will also be called in destructor
  ballot_file.close();
}

void IRElection::redistribute(uint8_t) {
  // TODO: redistribute among candidates

  // get loser ballot
  // find next choice
  // add to new candidate
  // return
}

void IRElection::announce_results() {
  // TODO: display winner, vote percentages, other info to screen
}

int IRElection::run() {
  // TODO: driver function for IR Elections

  // parse ballots
  // while no winner loop until determined
  // if winner
  // if tie for winner
  // tie break
  // declare winner/announce results (break)
  // else
  // find loser
  // if tie
  // tie break
  // eliminate loser
  // redistribute votes (loop)
  // return
}

std::string IRElection::log() const {
  // TODO: log election actions
}