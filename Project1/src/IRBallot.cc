// Copyright CSCI 5801 Spring 2021 Team 20

#include "IRBallot.h"

#include <cstddef>
#include <exception>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

IRBallot::IRBallot(const std::string& line) {
  // Make a vector for the columns in the csv line
  std::vector<std::string> columns;
  // Define a begin and end index for each column
  size_t begin = 0;
  size_t end = line.find(",");

  // Get the first column from the line
  columns.push_back(line.substr(begin, end - begin));

  // Get the remaining columns
  while (end != std::string::npos) {
    // Find the next column
    begin = end + 1;
    end = line.find(",", begin);

    // Get the column from the line
    columns.push_back(line.substr(begin, end - begin));
  }
  // TODO(Alex): Translate columns into the candidate index
}
IRBallot::~IRBallot() {
  // Nothing
}
uint8_t IRBallot::get_choice() const {
  // If we have run out of choices return max choice
  if (choice_index >= choices.size()) {
    return 0xFF;
  }
  // Return the choice
  return choices[choice_index];
}
void IRBallot::increment_choice() {
  // Go to the next choice if we still have choices left
  if (choice_index < choices.size()) {
    choice_index++;
  }
}
std::string IRBallot::log() const {
  // Make a string stream for output
  std::stringstream output;

  // Print the choices
  output << "IRBallot: choices=[";

  size_t i = 0;
  // Put the first choice onto the stream
  if (choices.size() > 0) {
    output << choices[i];
    ++i;
  }
  // Put all but the final element into the stream
  for (; i < choices.size(); ++i) {
    output << ", " << choices[i];
  }

  // Put the choice index into the stream
  output << "] choice_index=" << std::to_string(choice_index);

  // Put the current choice into the stream
  output << " get_choice()=" << std::to_string(get_choice());

  // Return the stream converted to a string
  return output.str();
}
