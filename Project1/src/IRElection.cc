
// Copyright CSCI 5801 Spring 2021 Team 20

#include "IRElection.h"

#include <sstream>
#include <string>
#include <algorithm>
#include <fstream>

IRElection::IRElection(const std::string& filename) : Election("IR", filename) {
  std::string line, name;
  for (int i = 0; i < 4; i++) {
    getline(ballot_file, line);
    if (i < 2) {
      continue;
    } else if (i == 2) {
      // parse candidates
      line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
      line.erase(std::remove(line.begin(), line.end(), '('), line.end());
      line.erase(std::remove(line.begin(), line.end(), ')'), line.end());
      std::istringstream ss(line);
      while(getline(ss, name, ',')) {
        candidates.push_back(IRCandidate(name.substr(0, name.length() - 1), name.substr(name.length() - 1)));
      }
    } else if (i == 3) {
      total_ballots = std::stoi(line);
    }
  }
}

void IRElection::parse_ballots() {
  // File is already open from Election constructor
  int lineNum = 0;
  std::string line;
  while (getline(ballot_file, line)) {
    ++lineNum;
    if (lineNum < 5) {
      continue;
    } else {
      // store ballots in candidates
      IRBallot* temp = new IRBallot(line);
      int c_idx = temp->get_choice();
      candidates.at(c_idx).add_ballot(IRBallot(line));
    }
  }
  // Can close here otherwise it will also be called in destructor
  ballot_file.close();
}

void IRElection::redistribute(uint8_t) {
  // TODO: redistribute among candidates

  // check for multiple losers
  // break tie if necessary
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
  bool found_winner = false;
  int majority = (total_ballots + 1) / 2;

  // parse ballots
  parse_ballots();

  // while no winner loop until determined
  while(!found_winner) {
    // check for majority
    // if majority then declare winner and break
    // if tie for majority then tie break
    // else redistribute and loop
  }
}

std::string IRElection::log() const {
  std::stringstream output;

  output << "IRElection: total_ballots=" << std::to_string(total_ballots);

  // Print the candidate names
  output << " candidates=[";

  auto candidate = candidates.begin();
  if (!candidates.empty()) {
    output << candidate->get_name();
    ++candidate;
  }
  for (; candidate != candidates.end(); ++candidate) {
    output << ", " << candidate->get_name();
    ++candidate;
  }
  output << "]";

  // TODO(someone): further logging?

  return output.str();
}