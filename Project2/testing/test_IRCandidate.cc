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
  } catch (const std::invalid_argument& e) {
    // TODO(Alex): determine appropriate exception to throw/catch

    ASSERT_EQ(can.get_tally(), prev_tally)
        << "Adding a ballot to eliminated candidate should not change the "
           "tally";
  }
}
/**
 * @brief Test if the @ref IRCandidate::eliminate() function works
 *
 */
TEST_F(fixture_IRCandidate, IRCandidateEliminate) {
  const std::string name = "Elliot";
  const std::string party = "Reform";

  IRCandidate can(name, party);

  // Add some ballots
  const constexpr uint16_t num_to_add = 25;
  for (uint16_t i = 0; i < num_to_add; ++i) {
    can.add_ballot(IRBallot("1,,,,"));
  }

  // Check that candidate is not initially eliminated
  ASSERT_EQ(can.get_eliminated(), false);

  can.eliminate();
  // Check that candidate is eliminated after calling eliminate
  ASSERT_EQ(can.get_eliminated(), true);
  ASSERT_EQ(can.get_tally(), num_to_add)
      << "Candidate should retain same tally after elimination";

  // Check that candidate is still eliminated after calling eliminate a second
  // time
  try {
    can.eliminate();

    FAIL()
        << "IRCandidate should thow exception on a second elimination attempt";
  } catch (const std::logic_error& e) {
    ASSERT_EQ(can.get_eliminated(), true)
        << "Candidate should stay eliminated after second elimination attempt";
    ASSERT_EQ(can.get_tally(), num_to_add)
        << "Candidate should retain same tally after second elimination";
  }
}
/**
 * @brief Test if the @ref IRCandidate::clear_ballots() properly clears ballots
 *
 */
TEST_F(fixture_IRCandidate, IRCandidateClearBallots) {
  const std::string name = "Elliot";
  const std::string party = "Reform";

  IRCandidate can(name, party);

  // Add some ballots
  const constexpr uint16_t num_to_add = 25;
  for (uint16_t i = 0; i < num_to_add; ++i) {
    can.add_ballot(IRBallot("1,,,,"));
  }
  // Make sure we have added the proper number of ballots
  ASSERT_EQ(can.get_tally(), num_to_add);
  ASSERT_EQ(can.get_ballots().size(), num_to_add);

  // Try to clear the candidate's ballots before eliminating them
  try {
    can.clear_ballots();
    FAIL() << "Clearing ballots before elimination should throw exception";
  } catch (const std::logic_error& e) {
    ASSERT_EQ(can.get_ballots().size(), num_to_add)
        << "Clearing ballots before elimination should throw exception before "
           "touching ballots";
  }

  // Eliminate the candidate
  can.eliminate();

  // Try to clear the candidate's ballots before eliminating them
  try {
    can.clear_ballots();
    ASSERT_EQ(can.get_ballots().size(), 0)
        << "Clearing ballots after elimination should result in zero ballots";
  } catch (const std::logic_error& e) {
    FAIL() << "Clearing ballots after elimination should not throw exception";
  }

  // Make sure the ballots are empty
  ASSERT_TRUE(can.get_ballots().empty());
}

TEST_F(fixture_IRCandidate, IRCandidateLog) {
  const std::string name = "Elliot";
  const std::string party = "Reform";

  IRCandidate can(name, party);

  // Add some ballots
  const constexpr uint16_t num_to_add = 25;
  for (uint16_t i = 0; i < num_to_add; ++i) {
    can.add_ballot(IRBallot("1,,,,"));
  }

  // Test logging
  std::string log = can.log();

  // Logging template
  // ASSERT_NE(log.find(), std::string::npos) << "Couldn't find  in log";

  ASSERT_NE(log.find("name=\'" + name + "\'"), std::string::npos)
      << "Couldn't find name in log";
  ASSERT_NE(log.find("party=\'" + party + "\'"), std::string::npos)
      << "Couldn't find party in log";
  ASSERT_NE(log.find("get_tally()=" + std::to_string(num_to_add)),
            std::string::npos)
      << "Couldn't find tally in log";
  ASSERT_NE(log.find("eliminated=false"), std::string::npos)
      << "Couldn't find eliminated status in log";

  can.eliminate();

  // Test logging after elimination
  log = can.log();

  // Logging template
  // ASSERT_NE(log.find(), std::string::npos) << "Couldn't find  in log";

  ASSERT_NE(log.find("name=\'" + name + "\'"), std::string::npos)
      << "Couldn't find name in log";
  ASSERT_NE(log.find("party=\'" + party + "\'"), std::string::npos)
      << "Couldn't find party in log";
  ASSERT_NE(log.find("get_tally()=" + std::to_string(num_to_add)),
            std::string::npos)
      << "Couldn't find tally in log";
  ASSERT_NE(log.find("eliminated=true"), std::string::npos)
      << "Couldn't find eliminated status in log";
}
