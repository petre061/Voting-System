// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#ifndef PROJECT1_TESTING_TEST_IRCANDIDATE_H_
#define PROJECT1_TESTING_TEST_IRCANDIDATE_H_

#include "IRCandidate.h"
#include "gtest/gtest.h"

class fixture_IRCandidate : public ::testing::Test {
 protected:
  // IRCandidate* candidate = nullptr;
 public:
  void SetUp() {
    // Set up any necessary data
  }

  void TearDown() {
    // Remove any data structures used
  }
};
#endif  // PROJECT1_TESTING_TEST_IRCANDIDATE_H_
