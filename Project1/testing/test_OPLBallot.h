// Copyright 2021 CSCI 5801 Spring 2021 Team 20

#ifndef PROJECT1_TESTING_TEST_OPLBALLOT_H_
#define PROJECT1_TESTING_TEST_OPLBALLOT_H_

#include "OPLBallot.h"
#include "gtest/gtest.h"

class fixture_OPLBallot : public ::testing::Test {
 protected:
  OPLBallot* ballot = nullptr;

 public:
  void SetUp() {
    // Remove any previous instances
    delete ballot;
    ballot = nullptr;
  }

  void TearDown() {
    // Delete ballot if we haven't cleaned it up
    delete ballot;
    ballot = nullptr;
  }
};
#endif  // PROJECT1_TESTING_TEST_OPLBALLOT_H_
