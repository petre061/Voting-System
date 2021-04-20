/**
 * @file main.cc
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file implements the main startup sequence for an election
 * @version 1.0
 * @date 2021-03-14
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>

#include "Election.h"
#include "ElectionFactory.h"

int main(int argc, char const* argv[]) {
  // Check that we have the right amount of arguments
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " election_file.csv" << std::endl;
    return 1;
  }

  // The election file is always the last one in the list of arguments
  std::string filename = argv[argc - 1];

  // Make an election using the file
  Election* election = ElectionFactory::create(filename);

  // Exit on factory failure. Factory will print error message
  if (election == nullptr) {
    return 1;
  }

  // Run the election logic
  int result = election->run();

  // Delete the election, calling destructors along the way
  delete election;

  // Return the result of out election run call
  return result;
}
