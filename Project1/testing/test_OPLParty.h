// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#ifndef PROJECT1_TESTING_TEST_OPLPARTY_H_
#define PROJECT1_TESTING_TEST_OPLPARTY_H_

#include "OPLParty.h"
#include "gtest/gtest.h"

class fixture_OPLParty : public ::testing::Test {
 protected:
  OPLParty* party = nullptr;

 public:
  void SetUp() {
    // Remove any previous instances
    delete party;
    party = nullptr;
  }

  void TearDown() {
    // Delete report if we haven't cleaned it up
    delete party;
    party = nullptr;
  }
};
#endif  // PROJECT1_TESTING_TEST_OPLPARTY_H_
