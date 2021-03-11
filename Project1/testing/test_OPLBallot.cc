// Copyright 2021, CSCI 5801 Spring 2021 Team 20
#include "test_OPLBallot.h"

#include <string>

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
TEST_F(fixture_OPLBallot, OPLBallotLogOnceChoice) {
  // Test a choice
  ballot = new OPLBallot(",,1,");

  std::string id = std::to_string(ballot->get_id());
  std::string expected = "OPLBallot: id=" + id + " get_choice()=2";

  ASSERT_EQ(ballot->log(), expected);
}

TEST_F(fixture_OPLBallot, OPLBallotLogNoChoice) {
  // Test no choice
  ballot = new OPLBallot(",,,");

  std::string id = std::to_string(ballot->get_id());
  std::string max_choice = std::to_string(Ballot::NO_CHOICE);

  std::string expected = "OPLBallot: id=" + id + " get_choice()=" + max_choice;
  ASSERT_EQ(ballot->log(), expected);
}
