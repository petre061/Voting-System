// Copyright 2021, CSCI 5801 Spring 2021 Team 20
#include "test_OPLParty.h"

#include "OPLCandidate.h"
#include "OPLParty.h"

TEST_F(fixture_OPLParty, OPLParty_getname) {
  // Test basic functionality, empty candidate
  OPLParty* party = new OPLParty("Democrat");
  ASSERT_EQ(party->get_name(),"Democrat");
  delete party;
}
TEST_F(fixture_OPLParty, OPLParty_gettally) {
  OPLParty* party = new OPLParty("Democrat");
  ASSERT_EQ(party->get_tally(), 0);
  delete party;
}
TEST_F(fixture_OPLParty, OPLParty_log) {
  OPLParty* party = new OPLParty("Democrat");
  ASSERT_EQ(party->log(), "OPL Party Democrat: []");
  delete party;
}

TEST_F(fixture_OPLParty, OPLParty_1party_1candidate) {
  OPLParty* party = new OPLParty("Spaghetti");
  OPLCandidate* candidate = new OPLCandidate("Ronald");
  // One candidate in party but no votes
  party->add_candidate(candidate);
  ASSERT_EQ(party->get_tally(), 0);
  delete party;
  delete candidate;
}

TEST_F(fixture_OPLParty, OPLParty_1party_1candidate_3ballots) {
  // One candidate in party, 1 vote
  OPLParty* party = new OPLParty("Spaghetti");
  OPLCandidate* candidate = new OPLCandidate("Ronald");
  party->add_candidate(candidate);
  OPLBallot* ballot1 = new OPLBallot("1,,,");
  OPLBallot* ballot2 = new OPLBallot("1,,,");
  OPLBallot* ballot3 = new OPLBallot("1,,,");
  candidate->add_ballot(*ballot1);
  candidate->add_ballot(*ballot2);
  candidate->add_ballot(*ballot3);
  ASSERT_EQ(party->get_tally(), 3);
  delete ballot1;
  delete ballot2;
  delete ballot3;
  delete candidate;
  delete party;
}
