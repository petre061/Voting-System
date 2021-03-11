// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#ifndef PROJECT1_TESTING_TEST_OPLELECTION_H_
#define PROJECT1_TESTING_TEST_OPLELECTION_H_

#include "OPLElection.h"
#include "gtest/gtest.h"

class fixture_OPLElection : public ::testing::Test {
 protected:
  OPLElection* election = nullptr;

 public:
  void SetUp() {
    // Remove any previous instances
    delete election;
    election = nullptr;
  }

  void TearDown() {
    // Delete report if we haven't cleaned it up
    delete election;
    election = nullptr;
  }
};
#endif  // PROJECT1_TESTING_TEST_OPLELECTION_H_
