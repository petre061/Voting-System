
// Copyright CSCI 5801 Spring 2021 Team 20

#include "TieBreaker.h"

// The singleton instance for the flipper
TieBreaker TieBreaker::instance;

bool TieBreaker::flip() {
  // Throw away some
  for (uint8_t i = 0; i < 100; i++) {
    instance.distribution(instance.twister);
  }
  // Return a random bool in our distribution
  return instance.distribution(instance.twister);
}
