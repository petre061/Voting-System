// Copyright 2021, CSCI 5801 Spring 2021 Team 20
#include "test_OPLElection.h"

#include "OPLCandidate.h"
#include "OPLParty.h"
#include "OPLBallot.h"

TEST_F(fixture_OPLElection, OPLElectionFunctionality) {
  // Test basic functionality, empty candidate
  election = new OPLElection("test_OPLElection_ex1.csv");
  election.run();
  //ASSERT_EQ(party->)
}