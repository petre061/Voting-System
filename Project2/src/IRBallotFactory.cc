/**
 * @file IRBallotFactory.cc
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief
 * @version 1.0
 * @date 2021-04-22
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "IRBallotFactory.h"

#include <algorithm>
#include <iostream>
#include <sstream>

IRBallotFactory::IRBallotFactory(const std::vector<std::string>& filenames) {
  for (const auto& name : filenames) {
    // Add a ifstream to the list of files, attempting to open the file at the
    // same time
    try {
      files.emplace_back(name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
    }
    // If the file is not open pop it off the list
    if (!files.back().good()) {
      std::cerr << "Unable to open \"" << name << "\", removing" << std::endl;
      files.pop_back();
    }
    total_ballots += files.back().get_num_ballots();
  }
  // Set the ballots remaining to the total ballots
  ballots_remaining = total_ballots;
  // Set the current file
  current_file = files.begin();

  // Check that we have at least 1 good file
  if (files.empty()) {
    throw std::logic_error("At least 1 valid IR election file must be passed");
  }

  candidates = files[0].get_candidates();

  // Verify candidates are the same for every ballot file
  for (auto& file : files) {
    auto& cans = file.get_candidates();
    // Size check
    if (cans.size() != candidates.size()) {
      throw std::invalid_argument(
          "Candidate numbers do not match between files");
    }
    // Candidate name and party check
    for (uint64_t index = 0; index < std::min(candidates.size(), cans.size());
         ++index) {
      if (candidates[index].first != cans[index].first) {
        throw std::invalid_argument(
            "Candidate names do not match between files");
      }
      if (candidates[index].second != cans[index].second) {
        throw std::invalid_argument(
            "Candidate parties do not match between files");
      }
    }
  }
}
uint64_t IRBallotFactory::get_remaining() const {
  // Return the remaining ballots
  return ballots_remaining;
}
IRBallot IRBallotFactory::get_ballot() {
  // Check that we have ballots remaining
  if (ballots_remaining == 0) {
    throw std::logic_error("Error: Attempted to get a ballot with none left");
  }
  // Seek to either the end of the list or the first file that has ballots
  // remaining
  while (current_file != files.end() && current_file->get_remaining() == 0) {
    ++current_file;
  }
  // Check that we didn't run out of files
  if (current_file == files.end()) {
    throw std::logic_error("Error: Attempted to get a ballot with none left");
  }
  // Get a line/ballot from the current file
  std::string line = current_file->getline();
  // Update the number of ballots remaining
  --ballots_remaining;
  // Return a ballot formed from the line
  return IRBallot(line);
}

const std::vector<std::pair<std::string, std::string>>&
IRBallotFactory::get_candiates() const {
  return candidates;
}

std::string IRBallotFactory::log() const {
  std::stringstream output;

  output << "IRBallotFactory:";

  output << " get_remaining()=" << std::to_string(get_remaining());

  output << " files=[";
  for (auto& file : files) {
    output << file.log() << std::endl;
  }
  output << "]";

  return output.str();
}
