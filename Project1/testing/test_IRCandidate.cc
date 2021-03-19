/**
 * @file test_IRCandidate.cc
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file implements the tests for the Independent Runoff candidate
 * class
 * @version 1.0
 * @date 2021-03-18
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "test_IRCandidate.h"

#include <string>

/**
 * @brief Test candidate gets proper name, party, begins with zero ballots and
 * is not eliminated on construction
 */
TEST_F(fixture_IRCandidate, IRCandidateConstructor) {
  const std::string name = "Elliot";
  const std::string party = "Reform";

  IRCandidate can(name, party);
  // Make sure candidate got proper name and party name
  ASSERT_EQ(can.get_party(), party);
  ASSERT_EQ(can.get_name(), name);
  // Make sure tally is initialized to zero
  ASSERT_EQ(can.get_tally(), 0);
  // Make sure the candidate is not eliminated
  ASSERT_EQ(can.get_eliminated(), false);

  // Test logging
  const std::string log = can.log();

  // Logging template
  // ASSERT_NE(log.find(), std::string::npos) << "Couldn't find  in log";

  ASSERT_NE(log.find("name=\'" + name + "\'"), std::string::npos)
      << "Couldn't find name in log";
  ASSERT_NE(log.find("party=\'" + party + "\'"), std::string::npos)
      << "Couldn't find party in log";
  ASSERT_NE(log.find("get_tally()=0"), std::string::npos)
      << "Couldn't find zero tally in log";
  ASSERT_NE(log.find("eliminated=false"), std::string::npos)
      << "Couldn't find eliminated status in log";
}
/**
 * @brief Test @ref add_ballot() properly adds ballots before elimination and
 * denies ballots after elimination
 *
 */
TEST_F(fixture_IRCandidate, IRCandidateAddBallot) {
  const std::string name = "Elliot";
  const std::string party = "Reform";

  IRCandidate can(name, party);

  // Make sure the candidate is not already eliminated
  ASSERT_EQ(can.get_eliminated(), false);

  // Add some ballots
  constexpr uint16_t num_to_add = 25;
  for (uint16_t i = 0; i < num_to_add; ++i) {
    can.add_ballot(IRBallot("1,,,,"));
  }
  // Make sure the candidate has the number of ballots we added
  ASSERT_EQ(can.get_tally(), num_to_add);

  // Eliminated candidate
  can.eliminate();

  // Make sure the candidate is eliminated now
  ASSERT_EQ(can.get_eliminated(), true);

  // Try adding ballot, should result in not adding ballot and exception
  const uint64_t prev_tally = can.get_tally();
  try {
    can.add_ballot(IRBallot("1,,,,"));

    ASSERT_EQ(can.get_tally(), prev_tally)
        << "Adding a ballot to eliminated candidate should not change the "
           "tally";
    FAIL() << "Adding a ballot to an eliminated IRCandidate should fail with "
              "exception";
  } catch (...) {
    // TODO(Alex): determine appropriate exception to throw/catch

    ASSERT_EQ(can.get_tally(), prev_tally)
        << "Adding a ballot to eliminated candidate should not change the "
           "tally";
  }
}
