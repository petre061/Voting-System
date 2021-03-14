// Copyright 2021, CSCI 5801 Spring 2021 Team 20
#include "test_OPLBallot.h"

#include <stdexcept>
#include <string>

// TEST_F(fixture_OPLBallot, OPLBallotCSVParse_1choice) {
//   // Test basic functionality
//   ballot = new OPLBallot("1,,,");
//   ASSERT_EQ(ballot->get_choice(), 0);
//   delete ballot;
// }
// TEST_F(fixture_OPLBallot, OPLBallotCSVParse_0choice) {
//     ballot = new OPLBallot(",,,,");
//     ASSERT_EQ(ballot->get_choice(), Ballot::NO_CHOICE);
//     delete ballot;
//   }
// TEST_F(fixture_OPLBallot, OPLBallotCSVParse_emptystring {
//   // Test empty string
//   try {
//     ballot = new OPLBallot("");
//     ballot = nullptr;
//     FAIL() << "Should not be able to create OPLBallot with empty string";
//     delete ballot;
//   } catch (const std::invalid_argument& e) {
//     ASSERT_EQ(e.what(), "Invalid Ballot - Empty");
//   } catch (...) {
//     ballot = nullptr;
//     FAIL() << "OPLBallot should throw std::invalid_argument on empty line";
//   }

//   ballot = nullptr;
// }

TEST_F(fixture_OPLBallot, OPLBallotLogOnceChoice) {
  // Test a choice
  ballot = new OPLBallot(",,1,,");
  std::string id = std::to_string(ballot->get_id());
  std::string expected = "OPLBallot " + id + " get_choice()=2";
  ASSERT_EQ(ballot->log(), expected);
}

TEST_F(fixture_OPLBallot, OPLBallotLogNoChoice) {
  // Test no choice
  ballot = new OPLBallot(",,,");

  std::string id = std::to_string(ballot->get_id());
  std::string max_choice = std::to_string(Ballot::NO_CHOICE);

  std::string expected = "OPLBallot " + id + " get_choice()=" + max_choice;
  ASSERT_EQ(ballot->log(), expected);
}
