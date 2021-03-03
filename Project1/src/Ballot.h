// Copyright CSCI 5801 Spring 2021 Team 20

#ifndef BALLOT_H_
#define BALLOT_H_

#include <atomic>
#include <cstdint>

#include "Loggable.h"

/**
 * @brief
 */
class Ballot : public Loggable {
 private:
  uint64_t id = 0xFFFFFFFF;

  static std::atomic<uint64_t> next_id;

  static uint64_t generate_id();

 public:
  Ballot();
  virtual ~Ballot();
  uint64_t get_id() const;
  virtual uint8_t get_choice() const = 0;
};

#endif  // BALLOT_H_
