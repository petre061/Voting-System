/**
 * @file ElectionFactory.cc
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file implements an ElectionFactory that produces elections based
 * on the input file
 * @version 1.0
 * @date 2021-03-14
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "ElectionFactory.h"

#include <cstring>
#include <fstream>
#include <iostream>

#include "IRElection.h"
#include "OPLElection.h"

Election* ElectionFactory::create(const std::vector<std::string>& filenames) {
  std::string type = "";

  for (auto& filename : filenames) {
    // Create a ifstream and try to open the specified file
    std::ifstream file(filename);

    // Check if we could open the specified file
    if (!file.is_open()) {
      std::cerr << "Failed to open " << filename << std::endl;
      std::cerr << "Reason: " << std::strerror(errno) << std::endl;
      return nullptr;
    }

    // Get the election type from the file
    std::string parsed_type;
    std::getline(file, parsed_type);
    if (type == "") {
      type = parsed_type;
    } else if (parsed_type != type) {
      std::cerr << "Mismatched election type \"" << parsed_type << "\" in \""
                << filename << "\"" << std::endl;
      return nullptr;
    }
  }

  // Return an Election based on the file header
  if (type.find("IR") != std::string::npos) {
    // Return a new Independent Runoff election if the file contains the proper
    // header
    // TODO(Alex): Update IRElection to take multiple files
    std::cerr << "WARNING: Using only the first file" << std::endl;
    return new IRElection(filenames[0]);
  } else if (type.find("OPL") != std::string::npos) {
    // Return a new Open Party Listing election if the file contains the proper
    // header
    // TODO(Alex): Update OPLElection to take multiple files
    std::cerr << "WARNING: Using only the first file" << std::endl;
    return new OPLElection(filenames[0]);
  }

  // Unknown election type
  std::cerr << "Unknown election type: \'" << type << "\'" << std::endl;
  return nullptr;
}
Election* ElectionFactory::create(const std::string& filename) {
  // Put the name into an empty list
  std::vector<std::string> filenames;
  filenames.push_back(filename);
  // Return the result of calling create with a list
  return ElectionFactory::create(filenames);
}
