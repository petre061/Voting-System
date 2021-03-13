// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#include "test_IRElection.h"

TEST_F(fixture_IRElection, IRElectionSRSExample) {
  // Test using the example file from the SRS document
  election = new IRElection("ballot_files/ir_example.csv");

  // Free up the election
  delete election;
  election = nullptr;
}
