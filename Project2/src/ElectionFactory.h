/**
 * @file ElectionFactory.h
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file declares the ElectionFactory class which produces elections
 * based on input files
 * @version 1.0
 * @date 2021-03-14
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PROJECT2_SRC_ELECTIONFACTORY_H_
#define PROJECT2_SRC_ELECTIONFACTORY_H_

#include <fstream>
#include <string>
#include <vector>

#include "Election.h"

/**
 * @brief This class makes different election types based on a given file
 */
class ElectionFactory {
 public:
  /**
   * @brief      Creates a new Election based on the file headers
   *
   * @param[in]  filenames  The filenames to use for the election
   *
   * @return     A pointer to the new Election type
   */
  static Election* create(const std::vector<std::string>& filenames);
  /**
   * @brief      Creates a new Election based on the file header
   *
   * @param[in]  filename  The filename to use for the election
   *
   * @return     A pointer to the new Election type
   */
  static Election* create(const std::string& filename);
};

#endif  // PROJECT2_SRC_ELECTIONFACTORY_H_
