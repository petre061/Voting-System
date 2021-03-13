// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#ifndef PROJECT1_TESTING_TEST_ELECTION_H_
#define PROJECT1_TESTING_TEST_ELECTION_H_

#include "Election.h"
#include "gtest/gtest.h"

/**
 * @brief Simple Election testing class
 */
class TestElection : public Election {

};

class fixture_Election : public ::testing::Test {
 protected:
  TestElection* election = nullptr;

 public:
  void SetUp() {
    // Remove any previous instances
    delete election;
    election = nullptr;
  }

  void TearDown() {
    // Delete election if we haven't cleaned it up
    delete election;
  }
};

#endif  // PROJECT1_TESTING_TEST_ELECTION_H_
