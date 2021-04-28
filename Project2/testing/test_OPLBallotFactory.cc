/**
 * @file test_OPLBallotFactory.cc
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief
 * @version 1.0
 * @date 2021-04-25
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "test_OPLBallotFactory.h"

#include <string>
#include <vector>

TEST_F(fixture_OPLBallotFactory, Constructor) {
  const std::vector<std::string> filenames = {
      "ballot_files/opl_half_first.csv", "ballot_files/opl_half_second.csv"};

  OPLBallotFactory factory(filenames);

  ASSERT_EQ(factory.get_remaining(), 18);
}
TEST_F(fixture_OPLBallotFactory, get_ballot) {
  const std::vector<std::string> filenames = {
      "ballot_files/opl_half_first.csv", "ballot_files/opl_half_second.csv"};

  OPLBallotFactory factory(filenames);

  ASSERT_EQ(factory.get_remaining(), 18);
  ASSERT_EQ(factory.get_ballot().get_choice(), 0);

  ASSERT_EQ(factory.get_remaining(), 17);
  ASSERT_EQ(factory.get_ballot().get_choice(), 0);

  ASSERT_EQ(factory.get_remaining(), 16);
  ASSERT_EQ(factory.get_ballot().get_choice(), 1);

  ASSERT_EQ(factory.get_remaining(), 15);
  ASSERT_EQ(factory.get_ballot().get_choice(), 4);

  ASSERT_EQ(factory.get_remaining(), 14);
  ASSERT_EQ(factory.get_ballot().get_choice(), 5);

  ASSERT_EQ(factory.get_remaining(), 13);
  ASSERT_EQ(factory.get_ballot().get_choice(), 3);

  ASSERT_EQ(factory.get_remaining(), 12);
  ASSERT_EQ(factory.get_ballot().get_choice(), 3);

  ASSERT_EQ(factory.get_remaining(), 11);
  ASSERT_EQ(factory.get_ballot().get_choice(), 0);

  ASSERT_EQ(factory.get_remaining(), 10);
  ASSERT_EQ(factory.get_ballot().get_choice(), 1);

  ASSERT_EQ(factory.get_remaining(), 9);
  ASSERT_EQ(factory.get_ballot().get_choice(), 0);

  ASSERT_EQ(factory.get_remaining(), 8);
  ASSERT_EQ(factory.get_ballot().get_choice(), 0);

  ASSERT_EQ(factory.get_remaining(), 7);
  ASSERT_EQ(factory.get_ballot().get_choice(), 1);

  ASSERT_EQ(factory.get_remaining(), 6);
  ASSERT_EQ(factory.get_ballot().get_choice(), 4);

  ASSERT_EQ(factory.get_remaining(), 5);
  ASSERT_EQ(factory.get_ballot().get_choice(), 5);

  ASSERT_EQ(factory.get_remaining(), 4);
  ASSERT_EQ(factory.get_ballot().get_choice(), 3);

  ASSERT_EQ(factory.get_remaining(), 3);
  ASSERT_EQ(factory.get_ballot().get_choice(), 3);

  ASSERT_EQ(factory.get_remaining(), 2);
  ASSERT_EQ(factory.get_ballot().get_choice(), 0);

  ASSERT_EQ(factory.get_remaining(), 1);
  ASSERT_EQ(factory.get_ballot().get_choice(), 1);

  ASSERT_EQ(factory.get_remaining(), 0);
}
TEST_F(fixture_OPLBallotFactory, get_num_seats) {
  const std::vector<std::string> filenames = {
      "ballot_files/opl_half_first.csv", "ballot_files/opl_half_second.csv"};

  OPLBallotFactory factory(filenames);

  ASSERT_EQ(factory.get_num_seats(), 3);
}
TEST_F(fixture_OPLBallotFactory, get_candidates) {
  const std::vector<std::string> filenames = {
      "ballot_files/opl_half_first.csv", "ballot_files/opl_half_second.csv"};

  OPLBallotFactory factory(filenames);

  auto& cans = factory.get_candidates();

  ASSERT_EQ(cans[0].first, "Pike");
  ASSERT_EQ(cans[0].second, "D");

  ASSERT_EQ(cans[1].first, "Foster");
  ASSERT_EQ(cans[1].second, "D");

  ASSERT_EQ(cans[2].first, "Deutsch");
  ASSERT_EQ(cans[2].second, "R");

  ASSERT_EQ(cans[3].first, "Borg");
  ASSERT_EQ(cans[3].second, "R");

  ASSERT_EQ(cans[4].first, "Jones");
  ASSERT_EQ(cans[4].second, "R");

  ASSERT_EQ(cans[5].first, "Smith");
  ASSERT_EQ(cans[5].second, "I");
}
TEST_F(fixture_OPLBallotFactory, log) {
  const std::vector<std::string> filenames = {
      "ballot_files/opl_half_first.csv", "ballot_files/opl_half_second.csv"};

  OPLBallotFactory factory(filenames);

  const std::string log = factory.log();

  for (auto& filename : filenames) {
    ASSERT_NE(log.find(filename), std::string::npos)
        << "Filename not found in log";
  }

  // Candidates
  ASSERT_NE(log.find("Pike (D)"), std::string::npos);
  ASSERT_NE(log.find("Foster (D)"), std::string::npos);
  ASSERT_NE(log.find("Deutsch (R)"), std::string::npos);
  ASSERT_NE(log.find("Borg (R)"), std::string::npos);
  ASSERT_NE(log.find("Jones (R)"), std::string::npos);
  ASSERT_NE(log.find("Smith (I)"), std::string::npos);

  // Remaining ballots
  ASSERT_NE(log.find("18"), std::string::npos);
  // Number of seats
  ASSERT_NE(log.find("3"), std::string::npos);
}
