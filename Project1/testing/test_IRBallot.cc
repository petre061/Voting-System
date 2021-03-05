// Copyright 2021, CSCI 5801 Spring 2021 Team 20
#include "test_IRBallot.h"

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
  ASSERT_EQ(ballot->get_choice(), IRBallot::NO_CHOICE);
}
