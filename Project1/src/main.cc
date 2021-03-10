// Copyright CSCI 5801 Spring 2021 Team 20
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

  return election->run();
}
