/**
 * @file BallotFile.cc
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file implements the BallotFile class
 * @version 1.0
 * @date 2021-04-21
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "BallotFile.h"

#include <iostream>

BallotFile::BallotFile(const std::string& fname)
    : filename(fname), file(filename) {
  // Check that we could open the file
  if (!file.is_open()) {
    std::cerr << "Unable to open \"" << filename << "\"" << std::endl;
  }
}
const std::string& BallotFile::get_type() const {
  // Return the BallotFile type
  return type;
}
uint64_t BallotFile::get_num_ballots() const {
  // Return the number of ballots
  return num_ballots;
}
