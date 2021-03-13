// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#ifndef PROJECT1_TESTING_TEST_BALLOT_H_
#define PROJECT1_TESTING_TEST_BALLOT_H_

#include <string>

#include "Ballot.h"
#include "gtest/gtest.h"
/**
 * @brief Simple Ballot testing class
 */
class TestBallot : public Ballot {
  uint8_t get_choice() const override { return Ballot::NO_CHOICE; }
  std::string log() const override {
    return "TEST BALLOT get_id()=" + std::to_string(get_id());
  }
};

class fixture_Ballot : public ::testing::Test {
 protected:
  TestBallot* ballot = nullptr;

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
