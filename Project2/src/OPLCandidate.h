// Copyright 2021, CSCI 5801 Spring 2021 Team 20
/**
 * @file OPLCandidate.cc
 * @author Peter Linden (linde764@umn.edu)
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file declares the OPL Candidate class.
 * @version 1.0
 * @date 2021-03-14
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef OPLCANDIDATE_H_
#define OPLCANDIDATE_H_

#include <cstdint>
#include <queue>
#include <sstream>
#include <string>

#include "Loggable.h"
#include "OPLBallot.h"

/**
 * @brief
 */
class OPLCandidate : public Loggable {
 private:
  std::string name;
  std::queue<OPLBallot> ballots;

 public:
 /**
  * @brief Construct a new OPLCandidate object
  * 
  * @param candidate 
  */
  explicit OPLCandidate(const std::string& candidate); // explicit keyword prevents compiler from using constructor for implicit conversion which can hide bugs
/**
 * @brief Add a ballot 
 * 
 * @return void 
 */
 void add_ballot(OPLBallot new_ballot);
													   
/**
 * @brief Get the tally object
 * 
 * @return uint64_t 
 */
  uint64_t get_tally();
  /**
   * @brief 
   * 
   * @return std::string 
   */
  std::string log() const override;
  /**
  * @return The name of the candidate
  */
  const std::string& get_name() const;
};

#endif  // OPLCANDIDATE_H_