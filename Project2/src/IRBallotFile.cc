/**
 * @file IRBallotFile.cc
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief
 * @version 1.0
 * @date 2021-04-22
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "IRBallotFile.h"

#include <iostream>

IRBallotFile::IRBallotFile(const std::string& fname) : BallotFile(fname) {
  // Temporary variable containing the contents of a line
  std::string line;

  // Read the election type
  if (!std::getline(file, line)) {
    std::cerr << "Unable to get election type from \"" << filename << "\""
              << std::endl;
  }
  // Verify the election type
  if (line == "IR") {
    // Set the type
    type = line;
  } else {
    std::cerr << "Error, passed election type \"" << line
              << "\" to IRBallotFile" << std::endl;
  }

  // Read the number of candidates in the election
  if (!std::getline(file, line)) {
    std::cerr << "Unable to get number of candidates from \"" << filename
              << "\"" << std::endl;
  }
  // Attempt to convert the string containing the number of candidates to the
  // number of candidates
  try {
    num_candidates = std::stoull(line);
  } catch (const std::exception& e) {
    std::cerr << "Unable to parse the number of candidates: " << e.what()
              << std::endl;
  }

  // Parse the candidates
  // Get the line for the candidates
  if (!std::getline(file, line)) {
    std::cerr << "Unable to get candidates from \"" << filename << "\""
              << std::endl;
  }
  // // parse candidates
  // Strip out spaces from the line
  line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

  std::istringstream ss(line);
  std::string column;
  // Parse all the candidates
  while (std::getline(ss, column, ',')) {
    // Get the position of the party name start and end
    size_t party_start = column.find("(");
    size_t party_end = column.find(")", party_start);
    // Check that we found the party
    if (party_start == std::string::npos || party_end == std::string::npos) {
      std::cerr << "Error parsing candidate" << std::endl;
    }
    // Add the parsed names to the list
    candidates.push_back(std::make_pair(
        column.substr(0, party_start),
        column.substr(party_start + 1, party_end - party_start - 1)));
  }

  // // Print the parsed candidates
  // for (auto& pair : candidates) {
  //   std::cout << "Name: \"" << pair.first << "\" Party: \"" << pair.second
  //             << "\"" << std::endl;
  // }

  // Verify the size of the candidates
  if (candidates.size() != num_candidates) {
    std::cerr << "Error reading the proper number of candidates from \""
              << filename << "\"" << std::endl;
  }

  // Read the number of ballots in the file
  if (!std::getline(file, line)) {
    std::cerr << "Unable to get number of ballots from \"" << filename << "\""
              << std::endl;
  }
  // Attempt to convert the string containing the number of ballots to the
  // number of ballots
  try {
    num_ballots = std::stoull(line);
    num_remaining_ballots = num_ballots;
  } catch (const std::exception& e) {
    std::cerr << "Unable to parse the number of ballots: " << e.what()
              << std::endl;
  }
}

uint64_t IRBallotFile::get_remaining() const {
  // Return the number of remaining ballots
  return num_remaining_ballots;
}
bool IRBallotFile::good() const {
  // Return the good flag on the file
  return file.good();
}
std::string IRBallotFile::getline() {
  // Throw error if there is a logic error
  if (num_remaining_ballots == 0) {
    throw std::logic_error("Out of ballots to read");
  }
  std::string line;
  // Get a line and decrement the remaining ballots
  std::getline(file, line);
  --num_remaining_ballots;

  return line;
}
std::string IRBallotFile::log() const {
  // TODO: this
  return "";
}
uint64_t IRBallotFile::get_num_candidates() const {
  // Return the number of candidates
  return num_candidates;
}

const std::vector<std::pair<std::string, std::string>>&
IRBallotFile::get_candidates() const {
  // return a constant reference to the candidates
  return candidates;
}
