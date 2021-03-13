// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#ifndef PROJECT1_TESTING_TEST_IRELECTION_H_
#define PROJECT1_TESTING_TEST_IRELECTION_H_

#include "IRElection.h"
#include "gtest/gtest.h"

class fixture_IRElection : public ::testing::Test {
 protected:
  IRElection* election = nullptr;

 public:
  void SetUp() {
    // Delete any previous test data
    delete election;
    election = nullptr;
  }

  void TearDown() {
    // Free up election
    delete election;
    election = nullptr;
  }
};
#endif  // PROJECT1_TESTING_TEST_IRELECTION_H_
