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

TEST_F(fixture_OPLParty, OPLParty_gettop_noties) {
  // One candidate in party, 1 vote
  OPLParty* party = new OPLParty("Spaghetti");
  OPLCandidate* candidate1 = new OPLCandidate("Eenie");
  OPLCandidate* candidate2 = new OPLCandidate("Meenie");
  OPLCandidate* candidate3 = new OPLCandidate("Miney");
  OPLCandidate* candidate4 = new OPLCandidate("Moe");    
  
  party->add_candidate(candidate1);
  party->add_candidate(candidate2);
  party->add_candidate(candidate3);
  party->add_candidate(candidate4);

  // 1 vote for Eenie
  OPLBallot* ballot1 = new OPLBallot("1,,,");
  candidate1->add_ballot(*ballot1);

  // 3 votes for Meenie
  OPLBallot* ballot2 = new OPLBallot(",1,,");
  OPLBallot* ballot3 = new OPLBallot(",1,,");
  OPLBallot* ballot4 = new OPLBallot(",1,,");
  candidate2->add_ballot(*ballot2);
  candidate2->add_ballot(*ballot3);
  candidate2->add_ballot(*ballot4);

  // No Ballots for Miney

  // 2 votes for Moe
  OPLBallot* ballot5 = new OPLBallot(",,,1");
  OPLBallot* ballot6 = new OPLBallot(",,,1");
  candidate4->add_ballot(*ballot5);
  candidate4->add_ballot(*ballot6);
  
  std::vector<std::string> actual = party->get_top_n_candidate_names(4);
  std::vector<std::string> expected = {"Meenie","Moe","Eenie","Miney"};
  ASSERT_EQ(actual, expected);
  delete ballot1;
  delete ballot2;
  delete ballot3;
  delete ballot4;
  delete ballot5;
  delete ballot6; 
  delete candidate1;
  delete candidate2;
  delete candidate3;
  delete candidate4;
  delete party;
}

// n > 