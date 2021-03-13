// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#include "test_IRElection.h"

TEST_F(fixture_IRElection, IRElectionSRSExample) {
  // Test using the example file from the SRS document
  election = new IRElection("ballot_files/ir_example.csv");

  // TODO(someone): more testing here

  ASSERT_EQ(election->run(), 0);

  // Free up the election
  delete election;
  election = nullptr;
}

TEST_F(fixture_IRElection, IRElectionRandom) {
  // Test using the example file from the SRS document
  election = new IRElection("ballot_files/ir_random.csv");

  // TODO(someone): more testing here

  ASSERT_EQ(election->run(), 0);

  // Free up the election
  delete election;
  election = nullptr;
}
