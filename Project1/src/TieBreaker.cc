
// Copyright CSCI 5801 Spring 2021 Team 20

#include "TieBreaker.h"

#include <queue>

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

uint8_t TieBreaker::resolve_tie(uint8_t num) {
  // TODO(Alex): look into rejection sampling

  // Set up a queue of indices to eliminate
  std::queue<uint8_t> indices;
  // Fill the queue
  for (uint8_t i = 0; i < num; ++i) {
    indices.push(i);
  }
  // Eliminate numbers until a single number remains
  while (indices.size() > 1) {
    // Take front 2
    uint8_t a = indices.front();
    indices.pop();
    uint8_t b = indices.front();
    indices.pop();
    // Eliminate one based on coin flip
    if (flip()) {
      // b was eliminated
      indices.push(a);
    } else {
      // a was eliminated
      indices.push(b);
    }
  }

  return indices.front();
}
