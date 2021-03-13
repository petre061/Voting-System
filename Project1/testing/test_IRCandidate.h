// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#ifndef PROJECT1_TESTING_TEST_IRCANDIDATE_H_
#define PROJECT1_TESTING_TEST_IRCANDIDATE_H_

#include "IRCandidate.h"
#include "gtest/gtest.h"

class fixture_IRCandidate : public ::testing::Test {
 protected:
  IRCandidate* candidate = nullptr;

 public:
  void SetUp() {
    // Remove any previous instances
    delete candidate;
    candidate = nullptr;
  }

  void TearDown() {
    // Delete candidate if we haven't cleaned it up
    delete candidate;
    candidate = nullptr;
  }
};
#endif  // PROJECT1_TESTING_TEST_IRCANDIDATE_H_
