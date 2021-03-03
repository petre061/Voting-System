// Copyright CSCI 5801 Spring 2021 Team 20

#ifndef IRBALLOT_H_
#define IRBALLOT_H_

#include <cstdint>
#include <string>
#include <vector>

#include "Ballot.h"

/**
 * @brief
 */
class IRBallot : public Ballot {
 private:
  std::vector<uint8_t> choices;
  uint8_t choice_index = 0;

 public:
  explicit IRBallot(const std::string& line);
  ~IRBallot();
  uint8_t get_choice() const override;
  void increment_choice();
  std::string log() const override;
};

#endif  // IRBALLOT_H_
