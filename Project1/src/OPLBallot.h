// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#ifndef PROJECT1_SRC_OPLBALLOT_H_
#define PROJECT1_SRC_OPLBALLOT_H_

#include <cstdint>
#include <sstream>
#include <string>

#include "Ballot.h"

/**
 * @brief
 */
class OPLBallot : public Ballot {
 private:
  uint8_t choice = 255;

 public:
  explicit OPLBallot(const std::string& line);
  uint8_t get_choice() const override;
  std::string log() const override;
};

#endif  // PROJECT1_SRC_OPLBALLOT_H_
