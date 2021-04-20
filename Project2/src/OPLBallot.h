// Copyright 2021, CSCI 5801 Spring 2021 Team 20
/**
 * @file OPLBallot.h
 * @author Alex Bohm (bohm0080@umn.edu)
 * @author Peter Linden (linde764@umn.edu)
 * @brief This file declares the OPL Ballot class.
 * @version 1.0
 * @date 2021-03-14
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef PROJECT1_SRC_OPLBALLOT_H_
#define PROJECT1_SRC_OPLBALLOT_H_

#include <cstdint>
#include <sstream>
#include <string>

#include "Ballot.h"

/**
 * @brief A @ref Ballot for an Open Party Listing election
 */
class OPLBallot : public Ballot {
 private:
  /**
   * @brief The choice that the ballot chose.
   */
  uint8_t choice = Ballot::NO_CHOICE;

 public:
  /**
   * @brief Construct a new OPLBallot using the given line from the CSV file
   *
   * @param line A line from the CSV ballots file
   */
  explicit OPLBallot(const std::string& line);
  /**
   * @brief Get the index of the chosen candidate
   *
   * Note: May return Ballot::NO_CHOICE if the person did not choose a candidate
   *
   * @return uint8_t The index of the candidate
   */
  uint8_t get_choice() const override;
  /**
   * @brief Produce an audit log entry from an instance's data.
   *
   * @return std::string The audit log entry
   */
  std::string log() const override;
};

#endif  // PROJECT1_SRC_OPLBALLOT_H_
