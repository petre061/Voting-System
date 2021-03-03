
// Copyright CSCI 5801 Spring 2021 Team 20

#include "Ballot.h"

#include <atomic>
#include <cstdint>

std::atomic<uint64_t> Ballot::next_id(0);

Ballot::Ballot() {
  // Generate a unique ID for this ballot
  id = generate_id();
}
Ballot::~Ballot() {
  // Nothing
}
uint64_t Ballot::generate_id() {
  // Return the next id and increment it for the next time
  return next_id++;
}

uint64_t Ballot::get_id() const {
  // Return the id of the ballot
  return id;
}
