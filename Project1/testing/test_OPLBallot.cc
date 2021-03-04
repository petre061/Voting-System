// Copyright 2021, CSCI 5801 Spring 2021 Team 20
#include "test_OPLBallot.h"

TEST_F(fixture_OPLBallot, OPLBallotCSVParse) {
  // Test basic functionality
  ballot = new OPLBallot("1,,,");
  ASSERT_EQ(ballot->get_choice(), 0);
  delete ballot;

  // Test no choices
  ballot = new OPLBallot(",,,,");
  ASSERT_EQ(ballot->get_choice(), 255);
  delete ballot;

  // Test empty string
  ballot = new OPLBallot("");
  ASSERT_EQ(ballot->get_choice(), 255);
  delete ballot;
}
