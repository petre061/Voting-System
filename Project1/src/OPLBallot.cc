// Copyright CSCI 5801 Spring 2021 Team 20
#include "OPLBallot.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

OPLBallot::OPLBallot(const std::string& line) {
  if (line.length() == 0) {
    throw std::invalid_argument("Invalid Ballot - Empty");
  }
  std::string line2parse = line;
  std::vector<std::string> parsedline;
  std::istringstream s_stream(line2parse);
  uint8_t i = 0;
  while (s_stream.good()) {
    std::string substr;
    getline(s_stream, substr, ',');
    // if the given substring is 1, indicating that a choice is selected, assign the choice attribute to this index within the ballot line
    if (substr == "1") {
      choice = i;
      // TODO: verify return is the correct statement here
      // exit(0);
      return;
    }
    i++;
    parsedline.push_back(substr);
  }
  throw std::invalid_argument("Invalid Ballot - no choice selected");
}
uint8_t OPLBallot::get_choice() const {
  // Return the current choice
  return choice;
}

std::string OPLBallot::log() const {
  // Make a string stream for output
  std::stringstream output;

  // Put the current choice into the stream
  output << "OPLBallot " << std::to_string(get_id())
         << " get_choice()=" << std::to_string(get_choice());

  // Return the stream converted to a string
  return output.str();
}
