// Copyright 2021, CSCI 5801 Spring 2021 Team 20
#include "test_OPLCandidate.h"
#include "OPLBallot.h"
#include "OPLCandidate.h"
#include <string>

TEST_F(fixture_OPLCandidate, OPLCandidateFunctionality) {
  // Test basic functionality, empty candidate
  candidate = new OPLCandidate("Barack Mobamba");
  ASSERT_EQ(candidate->log(), "Candidate Barack Mobamba: ballots =[]";
  ASSERT_EQ(candidate->get_tally(), 0;
  delete candidate;

  // Test 1 ballot
  candidate1 = new OPLCandidate("Al Gore");
  ballot = new OPLBallot("1,,,");
  candidate.add_ballot(ballot());
  ASSERT_EQ(candidate->get_tally(), 1);
  delete candidate1;
}