/**
 * @file IRCandidate.cc
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This class implements an Independent Runoff candidate
 * @version 0.1
 * @date 2021-03-14
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "IRCandidate.h"

#include <sstream>
#include <string>

IRCandidate::IRCandidate(const std::string& candidate_name,
                         const std::string& candidate_party)
    : name(candidate_name), party(candidate_party) {
  // Nothing else need init yet
}

void IRCandidate::add_ballot(IRBallot new_ballot) {
  if (!eliminated) {
    // Push the new ballot onto the queue
    ballots.push(new_ballot);
  } else {
    throw std::invalid_argument("Cannot add ballot to eliminated candidate " +
                                name);
  }
}

uint64_t IRCandidate::get_tally() const {
  // Return the number of ballots we have right now
  return ballots.size();
}

const std::queue<IRBallot>& IRCandidate::get_ballots() const {
  // TODO(Alex): Look into using move semantics/unique_ptr to move ballots out
  // of the class
  // Return the ballots
  return ballots;
}
void IRCandidate::clear_ballots() {
  while (!ballots.empty()) {
    ballots.pop();
  }
}
void IRCandidate::eliminate() {
  // Set the eliminated flag
  eliminated = true;
}
bool IRCandidate::get_eliminated() const {
  // Return the eliminated flag
  return eliminated;
}
const std::string& IRCandidate::get_name() const {
  // Return a constant reference to name
  return name;
}
const std::string& IRCandidate::get_party() const {
  // Return a constant reference to the party name
  return party;
}

std::string IRCandidate::log() const {
  // Set up a temporary string stream for creating the string
  std::stringstream output;
  // Write the various fields of IRCandidate to the stream
  output << "IRCandidate: name=\'" << name << "\'";
  output << " party=\'" << party << "\'";
  output << " get_tally()=" << std::to_string(get_tally());
  // Write the eliminated field using the alpha-representation of the boolean
  output << " eliminated=" << std::boolalpha << eliminated;

  // Return the string made from the stringstream
  return output.str();
}
