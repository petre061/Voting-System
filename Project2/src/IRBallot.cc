/**
 * @file IRBallot.cc
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file implements a ballot for an Independent Runoff election
 * @version 1.0
 * @date 2021-03-14
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "IRBallot.h"

#include <algorithm>
#include <cstddef>
#include <exception>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

bool IRBallot::choice_sorter(const std::pair<uint8_t, uint8_t>& a,
                             const std::pair<uint8_t, uint8_t>& b) {
  return a.second < b.second;
}

IRBallot::IRBallot(const std::string& line) {
  // Make a map for the columns in the csv line
  // std::map<candidate_index, candidate_rating> columns;
  std::vector<std::pair<uint8_t, uint8_t>> columns;
  std::string column = "";
  // Define a candidate index
  uint8_t candidate_index = 0;
  // Define a begin and end index for each column
  size_t begin = 0;
  size_t end = line.find(",");

  // Get the first column from the line
  column = line.substr(begin, end - begin);
  // Check column is formatted properly
  if (!column.empty() &&
      column.find_first_not_of("0123456789") == std::string::npos) {
    // Put the column choice into
    columns.push_back(std::make_pair(candidate_index, std::stoul(column)));
  } else if (column.empty()) {
    // Don't add choice to list
  } else {
    // Throw a invalid argument exception
    throw std::invalid_argument("Non-digit in csv column");
  }
  ++candidate_index;

  // Get the remaining columns
  while (end != std::string::npos) {
    // Find the next column
    begin = end + 1;
    end = line.find(",", begin);

    // Get the first column from the line
    column = line.substr(begin, end - begin);
    // Check column is formatted properly
    if (!column.empty() &&
        column.find_first_not_of("0123456789") == std::string::npos) {
      // Put the column choice into
      columns.push_back(std::make_pair(candidate_index, std::stoul(column)));
    } else if (column.empty()) {
      // Don't add choice to list
    } else {
      // Throw a invalid argument exception
      throw std::invalid_argument("Non-digit in csv column");
    }
    ++candidate_index;
  }

  // TODO(Optional): Validate ballot form

  // Sort the columns by the candidate preference
  std::sort(columns.begin(), columns.end(), choice_sorter);

  // Print the sorted columns
  // for (auto& p : columns) {
  //   std::cout << std::to_string(p.first) << ":" << std::to_string(p.second)
  //             << std::endl;
  // }

  // Put the sorted list into the choices
  for (auto& p : columns) {
    choices.push_back(p.first);
  }
}
uint8_t IRBallot::get_choice() const {
  // If we have run out of choices return max choice
  if (choice_index >= choices.size()) {
    return NO_CHOICE;
  }
  // Return the choice
  return choices[choice_index];
}
const std::vector<uint8_t>& IRBallot::get_choices() const {
  // Return reference to choices
  return choices;
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

  // Print the ballot type and id
  output << "IRBallot: id=" << std::to_string(get_id());

  // Print the choices
  output << " choices=[";

  size_t i = 0;
  // Put the first choice onto the stream
  if (choices.size() > 0) {
    output << std::to_string(choices[i]);
    ++i;
  }
  // Put all but the final element into the stream
  for (; i < choices.size(); ++i) {
    output << ", " << std::to_string(choices[i]);
  }

  // Put the choice index into the stream
  output << "] choice_index=" << std::to_string(choice_index);

  // Put the current choice into the stream
  output << " get_choice()=" << std::to_string(get_choice());

  // Return the stream converted to a string
  return output.str();
}