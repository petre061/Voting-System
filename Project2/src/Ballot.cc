/**
 * @file Ballot.cc
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file implements basic functionality for the Ballot class
 * @version 1.0
 * @date 2021-03-14
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "Ballot.h"

#include <atomic>
#include <cstdint>
// The next ballot's id. Starts at zero for the first ballot
std::atomic<uint64_t> Ballot::next_id(0);

Ballot::Ballot() {
  // Generate a unique ID for this ballot
  id = generate_id();
}
uint64_t Ballot::generate_id() {
  // Return the next id and increment it for the next time
  return next_id++;
}

uint64_t Ballot::get_id() const {
  // Return the id of the ballot
  return id;
}
