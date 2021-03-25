// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#include "test_IRElection.h"

TEST_F(fixture_IRElection, IRElectionSRSExample) {
  // Test using the example file from the SRS document
  IRElection election("ballot_files/ir_example.csv");

  ASSERT_EQ(election.run(), 0);

  // TODO(someone): more testing here

  // Rosen should win with 2/3 of the votes
}

TEST_F(fixture_IRElection, IRElectionRandom) {
  // Test using the example file from the SRS document
  IRElection election("ballot_files/ir_random.csv");

  ASSERT_EQ(election.run(), 0);

  // TODO(someone): more testing here
}

TEST_F(fixture_IRElection, IRElectionMPV) {
  // Test using the example file from the SRS document
  IRElection election("ballot_files/ir_majoritypopularVote.csv");

  ASSERT_EQ(election.run(), 0);

  // TODO(someone): more testing here
}

TEST_F(fixture_IRElection, IRElectionNM) {
  // Test using the example file from the SRS document
  IRElection election("ballot_files/ir_noMajority.csv");

  ASSERT_EQ(election.run(), 0);

  // TODO(someone): more testing here
}

TEST_F(fixture_IRElection, IRElectionOC) {
  // Test using the example file from the SRS document
  IRElection election("ballot_files/ir_oneCandidate.csv");

  ASSERT_EQ(election.run(), 0);

  // TODO(someone): more testing here
}

TEST_F(fixture_IRElection, IRElectionSV) {
  // Test using the example file from the SRS document
  IRElection election("ballot_files/ir_singleVote.csv");

  ASSERT_EQ(election.run(), 0);

  // TODO(someone): more testing here
}

TEST_F(fixture_IRElection, IRElectionTWT) {
  // Test using the example file from the SRS document
  IRElection election("ballot_files/ir_twoWayTie.csv");

  ASSERT_EQ(election.run(), 0);

  // TODO(someone): more testing here
}


