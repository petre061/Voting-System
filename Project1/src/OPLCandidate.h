// Copyright 2021, CSCI 5801 Spring 2021 Team 20

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
<<<<<<< HEAD
  explicit OPLCandidate(const std::string& candidate); // explicit keyword prevents compiler from using constructor for implicit conversion which can hide bugs
  void add_ballot(OPLBallot new_ballot);
=======
  // explicit keyword prevents compiler from using constructor for implicit
  // conversion which can hide bugs
  explicit OPLCandidate(const std::string& candidate_name);
>>>>>>> e71830705aaeaf562d0db4d202a6a32662c460e6
  uint64_t get_tally();
  std::string log() const override;
};

#endif  // OPLCANDIDATE_H_