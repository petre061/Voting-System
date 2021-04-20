// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#ifndef PROJECT1_TESTING_TEST_ELECTIONFACTORY_H_
#define PROJECT1_TESTING_TEST_ELECTIONFACTORY_H_

#include "Election.h"
#include "ElectionFactory.h"
#include "gtest/gtest.h"

class fixture_ElectionFactory : public ::testing::Test {
 protected:
  // Election* election = nullptr;

 public:
  void SetUp() {
    // Set up any data
  }

  void TearDown() {
    // Free up any data
  }
};
#endif  // PROJECT1_TESTING_TEST_ELECTIONFACTORY_H_
