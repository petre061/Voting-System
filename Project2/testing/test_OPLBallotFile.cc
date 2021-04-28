/**
 * @file test_OPLBallotFile.cc
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief
 * @version 1.0
 * @date 2021-04-22
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "test_OPLBallotFile.h"

#include <string>

TEST_F(fixture_OPLBallotFile, Constructor) {
  OPLBallotFile file("ballot_files/opl_example.csv");

  ASSERT_EQ(file.get_type(), "OPL");
  ASSERT_EQ(file.get_num_candidates(), 6);
  ASSERT_EQ(file.get_num_seats(), 3);
  ASSERT_EQ(file.get_num_ballots(), 9);
  ASSERT_EQ(file.get_remaining(), 9);
}
TEST_F(fixture_OPLBallotFile, get_candidates) {
  OPLBallotFile file("ballot_files/opl_example.csv");

  auto& cans = file.get_candidates();

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
TEST_F(fixture_OPLBallotFile, file_not_found) {
  OPLBallotFile file("ballot_files/opl_non_existent.csv");

  ASSERT_EQ(file.good(), false);
}

TEST_F(fixture_OPLBallotFile, getline) {
  OPLBallotFile file("ballot_files/opl_example.csv");

  ASSERT_EQ(file.get_type(), "OPL");
  ASSERT_EQ(file.get_num_candidates(), 6);
  ASSERT_EQ(file.get_num_seats(), 3);
  ASSERT_EQ(file.get_num_ballots(), 9);

  ASSERT_EQ(file.get_remaining(), 9);
  ASSERT_EQ(file.getline(), "1,,,,,");
  ASSERT_EQ(file.get_remaining(), 8);
  ASSERT_EQ(file.getline(), "1,,,,,");
  ASSERT_EQ(file.get_remaining(), 7);
  ASSERT_EQ(file.getline(), ",1,,,,");
  ASSERT_EQ(file.get_remaining(), 6);
  ASSERT_EQ(file.getline(), ",,,,1,");
  ASSERT_EQ(file.get_remaining(), 5);
  ASSERT_EQ(file.getline(), ",,,,,1");
  ASSERT_EQ(file.get_remaining(), 4);
  ASSERT_EQ(file.getline(), ",,,1,,");
  ASSERT_EQ(file.get_remaining(), 3);
  ASSERT_EQ(file.getline(), ",,,1,,");
  ASSERT_EQ(file.get_remaining(), 2);
  ASSERT_EQ(file.getline(), "1,,,,,");
  ASSERT_EQ(file.get_remaining(), 1);
  ASSERT_EQ(file.getline(), ",1,,,,");
  ASSERT_EQ(file.get_remaining(), 0);
}

TEST_F(fixture_OPLBallotFile, log) {
  const std::string filename = "ballot_files/opl_example.csv";

  OPLBallotFile file(filename);

  const std::string log = file.log();

  // ASSERT_NE(log.find(""), std::string::npos) << "";

  ASSERT_NE(log.find(filename), std::string::npos);

  // Num seats
  ASSERT_NE(log.find("3"), std::string::npos);
  // Num ballots
  ASSERT_NE(log.find("9"), std::string::npos);

  // Candidates
  ASSERT_NE(log.find("Pike (D)"), std::string::npos);
  ASSERT_NE(log.find("Foster (D)"), std::string::npos);
  ASSERT_NE(log.find("Deutsch (R)"), std::string::npos);
  ASSERT_NE(log.find("Borg (R)"), std::string::npos);
  ASSERT_NE(log.find("Jones (R)"), std::string::npos);
  ASSERT_NE(log.find("Smith (I)"), std::string::npos);
}
