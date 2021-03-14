// Copyright 2021, CSCI 5801 Spring 2021 Team 20
#include "test_OPLCandidate.h"

#include <string>

#include "OPLBallot.h"
#include "OPLCandidate.h"

TEST_F(fixture_OPLCandidate, OPLCandidate_empty_log) {
  // Test basic functionality, empty candidate
  OPLCandidate* candidate = new OPLCandidate("Barack Mobamba");
  ASSERT_EQ(candidate->log(), "Candidate Barack Mobamba: ballots =[]");
  delete candidate;
}
TEST_F(fixture_OPLCandidate, OPLCandidate_empty_gettally) {
  OPLCandidate* candidate = new OPLCandidate("Barack Mobamba");
  ASSERT_EQ(candidate->get_tally(), 0);
  delete candidate;
}
TEST_F(fixture_OPLCandidate, OPLCandidate_gettally) {
  // Test 1 ballot
  OPLCandidate* candidate1 = new OPLCandidate("Al Gore");
  candidate1->add_ballot(OPLBallot("1,,,"));
  ASSERT_EQ(candidate1->get_tally(), 1);
  delete candidate1;
}
