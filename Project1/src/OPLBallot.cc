// Copyright CSCI 5801 Spring 2021 Team 20
#include "OPLBallot.h"
#include <iostream>
#include <vector>
#include <sstream>
// Step 1: Create stream from given string
// Step 2: While the stream is not completed
// Step 2.1: Take item before comma
// Step 2.2: Add item into a vector
// Step 3: Return the vector

OPLBallot::OPLBallot(std::string& line) {
  // TODO(Alex, Peter): Implement line parsing
  //id = generate_id();
  string line2parse = line;
    vector<string> parsedline;
    stringstream s_stream(line2parse);
    uint8_t i = 0;
    while(s_stream.good()) {
        string substr;
        getline(s_stream, substr, ',');
        if(substr == "1") {
            choice = i;
            exit();
        }
        i++;
        parsedline.push_back(substr);
    }
}

OPLBallot::~OPLBallot() {
  // nothing
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

// uint64_t OPLBallot::get_id() const {
//   return id;
// }
