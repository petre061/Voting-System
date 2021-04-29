// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#ifndef PROJECT1_TESTING_TEST_VALIDATOR_H_
#define PROJECT1_TESTING_TEST_VALIDATOR_H_

#include "Validator.h"
#include "gtest/gtest.h"

class fixture_VALIDATOR : public ::testing::Test {
 protected:
 public:
  void SetUp() {
    // Nothing
  }

  void TearDown() {
    // Nothing
  }
};
#endif  // PROJECT1_TESTING_TEST_VALIDATOR_H_