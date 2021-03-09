// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#ifndef OPLCANDIDATE_H_
#define OPLCANDIDATE_H_

#include <cstdint>
#include <sstream>
#include <string>
#include <queue>

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
  explicit OPLCandidate(const std::string& name); // explicit keyword prevents compiler from using constructor for implicit conversion which can hide bugs
  uint64_t get_tally();
  std::string log() const override;
};

#endif  // OPLCANDIDATE_H_