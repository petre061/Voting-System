// Copyright 2021, CSCI 5801 Spring 2021 Team 20
#include "test_IRBallot.h"

#include <string>

#include "IRBallot.h"

TEST_F(fixture_IRBallot, IRBallotCSVParse) {
  // Test basic functionality
  IRBallot ballot("1,2,3,4");
  ASSERT_EQ(ballot.get_choices().size(), 4);

  // Test no choices
  ballot = IRBallot(",,,,");
  ASSERT_EQ(ballot.get_choices().size(), 0);
  ASSERT_EQ(ballot.get_choice(), Ballot::NO_CHOICE);

  // Test empty string
  ballot = IRBallot("");
  ASSERT_EQ(ballot.get_choices().size(), 0);
  ASSERT_EQ(ballot.get_choice(), Ballot::NO_CHOICE);

  // Test single positions

  ballot = IRBallot("1,,,,");
  ASSERT_EQ(ballot.get_choice(), 0);

  ballot = IRBallot(",1,,,");
  ASSERT_EQ(ballot.get_choice(), 1);

  ballot = IRBallot(",,1,,");
  ASSERT_EQ(ballot.get_choice(), 2);

  ballot = IRBallot(",,,1,");
  ASSERT_EQ(ballot.get_choice(), 3);

  ballot = IRBallot(",,,,1");
  ASSERT_EQ(ballot.get_choice(), 4);
}
TEST_F(fixture_IRBallot, IRBallotOrder) {
  // Test in order
  IRBallot ballot("1,2,3,4,5");

  ASSERT_EQ(ballot.get_choice(), 0);
  ballot.increment_choice();

  ASSERT_EQ(ballot.get_choice(), 1);
  ballot.increment_choice();

  ASSERT_EQ(ballot.get_choice(), 2);
  ballot.increment_choice();

  ASSERT_EQ(ballot.get_choice(), 3);
  ballot.increment_choice();

  ASSERT_EQ(ballot.get_choice(), 4);
  ballot.increment_choice();

  ASSERT_EQ(ballot.get_choice(), Ballot::NO_CHOICE);

  // Test in reverse order
  ballot = IRBallot("5,4,3,2,1");

  ASSERT_EQ(ballot.get_choice(), 4);
  ballot.increment_choice();

  ASSERT_EQ(ballot.get_choice(), 3);
  ballot.increment_choice();

  ASSERT_EQ(ballot.get_choice(), 2);
  ballot.increment_choice();

  ASSERT_EQ(ballot.get_choice(), 1);
  ballot.increment_choice();

  ASSERT_EQ(ballot.get_choice(), 0);
  ballot.increment_choice();

  ASSERT_EQ(ballot.get_choice(), Ballot::NO_CHOICE);

  // Test in random order
  ballot = IRBallot("2,4,5,1,3");

  ASSERT_EQ(ballot.get_choice(), 3);
  ballot.increment_choice();

  ASSERT_EQ(ballot.get_choice(), 0);
  ballot.increment_choice();

  ASSERT_EQ(ballot.get_choice(), 4);
  ballot.increment_choice();

  ASSERT_EQ(ballot.get_choice(), 1);
  ballot.increment_choice();

  ASSERT_EQ(ballot.get_choice(), 2);
  ballot.increment_choice();

  ASSERT_EQ(ballot.get_choice(), Ballot::NO_CHOICE);
}

TEST_F(fixture_IRBallot, IRBallotIncrement) {
  // Test basic functionality
  IRBallot ballot("1,2,3,4");
  ASSERT_EQ(ballot.get_choice(), 0);

  ballot.increment_choice();
  ASSERT_EQ(ballot.get_choice(), 1);

  ballot.increment_choice();
  ASSERT_EQ(ballot.get_choice(), 2);

  ballot.increment_choice();
  ASSERT_EQ(ballot.get_choice(), 3);

  ballot.increment_choice();
  // Choice should now be max (out of range of candidate)
  ASSERT_EQ(ballot.get_choice(), Ballot::NO_CHOICE);
  ballot.increment_choice();
  // Choice should still be max (out of range of candidate)
  ASSERT_EQ(ballot.get_choice(), Ballot::NO_CHOICE);
}

TEST_F(fixture_IRBallot, IRBallotLog) {
  IRBallot ballot("1,2,3,4");

  std::string id = std::to_string(ballot.get_id());
  std::string expected;

  expected = "IRBallot: id=" + id +
             " choices=[0, 1, 2, 3] choice_index=0 get_choice()=0";
  ASSERT_EQ(ballot.log(), expected);

  ballot.increment_choice();

  expected = "IRBallot: id=" + id +
             " choices=[0, 1, 2, 3] choice_index=1 get_choice()=1";
  ASSERT_EQ(ballot.log(), expected);

  ballot.increment_choice();

  expected = "IRBallot: id=" + id +
             " choices=[0, 1, 2, 3] choice_index=2 get_choice()=2";
  ASSERT_EQ(ballot.log(), expected);

  ballot.increment_choice();

  expected = "IRBallot: id=" + id +
             " choices=[0, 1, 2, 3] choice_index=3 get_choice()=3";
  ASSERT_EQ(ballot.log(), expected);

  ballot.increment_choice();

  std::string max_choice = std::to_string(Ballot::NO_CHOICE);

  expected = "IRBallot: id=" + id +
             " choices=[0, 1, 2, 3] choice_index=4 get_choice()=" + max_choice;
  ASSERT_EQ(ballot.log(), expected);
}
