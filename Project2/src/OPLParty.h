// Copyright 2021, CSCI 5801 Spring 2021 Team 20
/**
 * @file OPLElection.cc
 * @author Peter Linden (linde764@umn.edu)
 * @author Nikhil Srikanth (srika018@umn.edu)
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file declares the OPL Party class.
 * @version 1.0
 * @date 2021-03-14
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef OPLPARTY_H_
#define OPLPARTY_H_

#include <cstdint>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

#include "Loggable.h"
#include "OPLCandidate.h"
#include "TieBreaker.h"

/**
 * @brief
 */
class OPLParty : public Loggable {
 private:
  std::string pname;
  std::vector<OPLCandidate*> candidates;

 public:
  /**
   * @brief Construct a new OPLParty object
   *
   * @param name
   */
  explicit OPLParty(const std::string& name);
  /**
   * @brief Get the tally object
   *
   * @return uint64_t
   */
  uint64_t get_tally();
  /**
   * @brief
   *
   * @param new_candidate
   */
  void add_candidate(OPLCandidate* new_candidate);
  /**
   * @brief
   *
   * @return std::string
   */
  std::string log() const override;
  /**
   * @brief Get the name object
   *
   * @return std::string
   */
  std::string get_name();
  /**
   * @brief Get the top n candidate names
   *
   * @param n
   * @return std::vector<std::string>
   */
  std::vector<std::string> get_top_n_candidate_names(uint64_t n) const;
  /**
   * @brief Get the candidates vector
   *
   * @return std::vector<OPLCandidate*>
   */
  const std::vector<OPLCandidate*>& get_candidates() const;
};

#endif  // OPLPARTY_H_