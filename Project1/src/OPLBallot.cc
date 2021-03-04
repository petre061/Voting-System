// Copyright CSCI 5801 Spring 2021 Team 20
#include "OPLBallot.h"

OPLBallot::OPLBallot(const std::string& line) {
  // TODO(Alex, Peter): Implement line parsing
}
uint8_t OPLBallot::get_choice() const {
  // Return the current choice
  return choice;
}

std::string OPLBallot::log() const {
  // Make a string stream for output
  std::stringstream output;

  // Put the current choice into the stream
  output << "OPLBallot: get_choice()=" << std::to_string(get_choice());

  // Return the stream converted to a string
  return output.str();
}
