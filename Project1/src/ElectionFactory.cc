// Copyright 2021 CSCI 5801 Spring 2021 Team 20
#include "ElectionFactory.h"

#include <cstring>
#include <fstream>
#include <iostream>

#include "IRElection.h"
#include "OPLElection.h"

Election* ElectionFactory::create(const std::string& filename) {
  // Create a ifstream and try to open the specified file
  std::ifstream file(filename);
  // Election type from file
  std::string type;

  // Check if we could open the specified file
  if (!file.is_open()) {
    std::cerr << "Failed to open " << filename << std::endl;
    std::cerr << "Reason: " << std::strerror(errno) << std::endl;
    return nullptr;
  }

  // Get the election type from the file
  std::getline(file, type);

  // Return an Election based on the file header
  if (type.find("IR") != std::string::npos) {
    // Return a new Independent Runoff election if the file contains the proper
    // header
    return new IRElection(filename);
  } else if (type.find("OPL") != std::string::npos) {
    // Return a new Open Party Listing election if the file contains the proper
    // header
    return new OPLElection(filename);
  }

  // Unknown election type
  std::cerr << "Unknown election type: \'" << type << "\'" << std::endl;
  return nullptr;
}
