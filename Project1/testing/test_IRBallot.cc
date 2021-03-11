// Copyright 2021, CSCI 5801 Spring 2021 Team 20
#include "test_IRBallot.h"

#include <string>

#include "IRBallot.h"

TEST_F(fixture_IRBallot, IRBallotCSVParse) {
  // Test basic functionality
  ballot = new IRBallot("1,2,3,4");
  ASSERT_EQ(ballot->get_choices().size(), 4);
  delete ballot;

  // Test no choices
  ballot = new IRBallot(",,,,");
  ASSERT_EQ(ballot->get_choices().size(), 0);
  delete ballot;

  // Test empty string
  ballot = new IRBallot("");
  ASSERT_EQ(ballot->get_choices().size(), 0);
}

TEST_F(fixture_IRBallot, IRBallotIncrement) {
  // Test basic functionality
  ballot = new IRBallot("1,2,3,4");
  ASSERT_EQ(ballot->get_choice(), 0);

  ballot->increment_choice();
  ASSERT_EQ(ballot->get_choice(), 1);

  ballot->increment_choice();
  ASSERT_EQ(ballot->get_choice(), 2);

  ballot->increment_choice();
  ASSERT_EQ(ballot->get_choice(), 3);
  // Choice should now be max (out of range of candidate)
  ballot->increment_choice();
  ASSERT_EQ(ballot->get_choice(), Ballot::NO_CHOICE);
}

TEST_F(fixture_IRBallot, IRBallotLog) {
  ballot = new IRBallot("1,2,3,4");

  std::string id = std::to_string(ballot->get_id());
  std::string expected;

  expected = "IRBallot: id=" + id +
             " choices=[0, 1, 2, 3] choice_index=0 get_choice()=0";
  ASSERT_EQ(ballot->log(), expected);

  ballot->increment_choice();

  expected = "IRBallot: id=" + id +
             " choices=[0, 1, 2, 3] choice_index=1 get_choice()=1";
  ASSERT_EQ(ballot->log(), expected);

  ballot->increment_choice();

  expected = "IRBallot: id=" + id +
             " choices=[0, 1, 2, 3] choice_index=2 get_choice()=2";
  ASSERT_EQ(ballot->log(), expected);

  ballot->increment_choice();

  expected = "IRBallot: id=" + id +
             " choices=[0, 1, 2, 3] choice_index=3 get_choice()=3";
  ASSERT_EQ(ballot->log(), expected);

  ballot->increment_choice();

  std::string max_choice = std::to_string(Ballot::NO_CHOICE);

  expected = "IRBallot: id=" + id +
             " choices=[0, 1, 2, 3] choice_index=4 get_choice()=" + max_choice;
  ASSERT_EQ(ballot->log(), expected);
}
