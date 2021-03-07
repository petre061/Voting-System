// Copyright CSCI 5801 Spring 2021 Team 20

#ifndef PROJECT1_TESTING_TEST_OPLCANDIDATE_H_
#define PROJECT1_TESTING_TEST_OPLCANDIDATE_H_

#include "OPLCandidate.h"
#include "gtest/gtest.h"

class fixture_OPLBallot : public ::testing::Test {
 protected:
  OPLCandidate* candidate = nullptr;

 public:
  void SetUp() {
    // Remove any previous instances
    delete candidate;
    candidate = nullptr;
  }

  void TearDown() {
    // Delete ballot if we haven't cleaned it up
    delete candidate;
  }
};
#endif  // PROJECT1_TESTING_TEST_OPLCANDIDATE_H_