// Copyright 2021 CSCI 5801 Spring 2021 Team 20

#ifndef PROJECT1_SRC_ELECTIONFACTORY_H_
#define PROJECT1_SRC_ELECTIONFACTORY_H_

#include <fstream>
#include <string>

#include "Election.h"

/**
 * @brief This class makes different election types based on a given file
 */
class ElectionFactory {
 public:
  /**
   * @brief      Creates a new Election based on the file header
   *
   * @param[in]  filename  The filename to check
   *
   * @return     A pointer to the new Election type
   */
  static Election* create(const std::string& filename);
};

#endif  // PROJECT1_SRC_ELECTIONFACTORY_H_
