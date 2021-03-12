// Copyright CSCI 5801 Spring 2021 Team 20

#ifndef PROJECT1_TESTING_TEST_BALLOT_H_
#define PROJECT1_TESTING_TEST_BALLOT_H_

#include "Ballot.h"
#include "gtest/gtest.h"

class fixture_Ballot : public ::testing::Test {
 protected:
  Ballot* ballot = nullptr;

 public:
  void SetUp() {
    // Remove any previous instances
    delete ballot;
    ballot = nullptr;
  }

  void TearDown() {
    // Delete ballot if we haven't cleaned it up
    delete ballot;
  }
};
#endif  // PROJECT1_TESTING_TEST_BALLOT_H_
