// Copyright CSCI 5801 Spring 2021 Team 20

#ifndef IRELECTION_H_
#define IRELECTION_H_

#include <cstdint>
#include <string>

#include "Election.h"
#include "IRBallot.h"

/**
 * @brief
 */
class IRElection : public Election {
 private:
  // TODO: private vector of IR Candidates
  void parse_ballots();
  void redistribute(uint8_t candidate_index);
  void announce_results();

 public:
  explicit IRElection(const std::string& filename);
  int run() override;
  std::string log() const override;
};

#endif