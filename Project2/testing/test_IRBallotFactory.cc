/**
 * @file test_IRBallotFactory.cc
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief
 * @version 1.0
 * @date 2021-04-22
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "test_IRBallotFactory.h"

#include <string>
#include <vector>

#include "IRBallotFactory.h"

TEST_F(fixture_IRBallotFactory, IRBallotFactoryConstructor) {
  IRBallotFactory factory(
      {"ballot_files/ir_half_first.csv", "ballot_files/ir_half_second.csv"});

  ASSERT_EQ(factory.get_remaining(), 36);
}
TEST_F(fixture_IRBallotFactory, get_ballot) {
  IRBallotFactory factory(
      {"ballot_files/ir_half_first.csv", "ballot_files/ir_half_second.csv"});

  ASSERT_EQ(factory.get_remaining(), 36);
  IRBallot b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 35);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 34);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 33);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 32);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 31);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 30);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 29);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 28);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 27);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 26);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 25);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 24);

  // Make sure this ballot is the one from the second file
  b = factory.get_ballot();
  ASSERT_EQ(b.get_choice(), 0);
  b.increment_choice();
  ASSERT_EQ(b.get_choice(), 2);
  b.increment_choice();
  ASSERT_EQ(b.get_choice(), Ballot::NO_CHOICE);

  ASSERT_EQ(factory.get_remaining(), 23);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 22);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 21);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 20);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 19);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 18);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 17);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 16);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 15);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 14);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 13);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 12);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 11);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 10);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 9);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 8);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 7);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 6);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 5);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 4);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 3);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 2);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 1);
  b = factory.get_ballot();
  ASSERT_EQ(factory.get_remaining(), 0);
}

TEST_F(fixture_IRBallotFactory, get_candidates) {
  IRBallotFactory factory(
      {"ballot_files/ir_half_first.csv", "ballot_files/ir_half_second.csv"});

  auto& cans = factory.get_candiates();

  // ASSERT_EQ(cans[].first, "");
  // ASSERT_EQ(cans[].second, "");

  ASSERT_EQ(cans[0].first, "Rosen");
  ASSERT_EQ(cans[0].second, "D");

  ASSERT_EQ(cans[1].first, "Kleinberg");
  ASSERT_EQ(cans[1].second, "R");

  ASSERT_EQ(cans[2].first, "Chou");
  ASSERT_EQ(cans[2].second, "I");

  ASSERT_EQ(cans[3].first, "Royce");
  ASSERT_EQ(cans[3].second, "L");
}
TEST_F(fixture_IRBallotFactory, log) {
  const std::vector<std::string> filenames = {
      "ballot_files/ir_half_first.csv", "ballot_files/ir_half_second.csv"};

  IRBallotFactory factory(filenames);

  const std::string log = factory.log();

  // Make sure all the given filenames appear in the log
  for (auto& filename : filenames) {
    ASSERT_NE(log.find(filename), std::string::npos)
        << "Unable to find \"" << filename << "\" in log";
  }

  // ASSERT_NE(log.find(""), std::string::npos) << "";

  // Make sure the candidates are in the log
  ASSERT_NE(log.find("Rosen (D)"), std::string::npos)
      << "Unable to find candidate in log";
  ASSERT_NE(log.find("Kleinberg (R)"), std::string::npos)
      << "Unable to find candidate in log";
  ASSERT_NE(log.find("Chou (I)"), std::string::npos)
      << "Unable to find candidate in log";
  ASSERT_NE(log.find("Royce (L)"), std::string::npos)
      << "Unable to find candidate in log";

  // Make sure number of ballots is in the log
  ASSERT_NE(log.find("36"), std::string::npos)
      << "Unable to find number of remaining ballots";
}
