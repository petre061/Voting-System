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
}
TEST_F(fixture_OPLBallotFile, get_line) {
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
