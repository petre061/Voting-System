// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#ifndef OPLPARTY_H_
#define OPLPARTY_H_

#include <cstdint>
#include <queue>
#include <sstream>
#include <string>

#include "Loggable.h"
#include "OPLCandidate.h"

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
  explicit OPLParty(
      const std::string&
          name);
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
   * @brief Get the top n candidate names object
   * 
   * @param n 
   * @return std::vector<std::string> 
   */
  std::vector<std::string> get_top_n_candidate_names(int n);
};

#endif  // OPLPARTY_H_