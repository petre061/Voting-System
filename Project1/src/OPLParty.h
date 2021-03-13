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
  explicit OPLParty(
      const std::string&
          name);  // explicit keyword prevents compiler from using constructor
                  // for implicit conversion which can hide bugs
  uint64_t get_tally();
  void add_candidate(OPLCandidate* new_candidate);
  std::string log() const override;
  std::string get_name();
  std::vector<std::string> get_top_n_candidate_names(int n);
};

#endif  // OPLPARTY_H_