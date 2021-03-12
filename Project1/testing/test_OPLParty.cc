// Copyright 2021, CSCI 5801 Spring 2021 Team 20
#include "test_OPLParty.h"
#include "OPLParty.h"
#include "OPLCandidate.h"

TEST_F(fixture_OPLParty, OPLPartyFunctionality) {
  // Test basic functionality, empty candidate
  party = new OPLParty("Democrat");
  ASSERT_EQ(party->get_tally(), 0);
  ASSERT_EQ(party->lot(),"OPL Party Democrat: []");
  delete party;

// Test 1 candidate and 1 ballot
  party1 = new OPLParty("Spaghetti");
  candidate1 = new OPLCandidate("Ronald");
  ballot = new OPLBallot("1,,,")
  // One candidate in party but no votes
  party1.add_candidate(candidate1);
  ASSERT_EQ(part1->get_tally(), 1);
  // One candidate in party, 1 vote
  candidate1.add_ballot(ballot);
  ASSERT_EQ(part1->get_tally(), 1);
  delete ballot;
}
