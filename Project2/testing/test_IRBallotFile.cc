/**
 * @file test_IRBallotFile.cc
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief
 * @version 1.0
 * @date 2021-04-22
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "test_IRBallotFile.h"

#include <string>

TEST_F(fixture_IRBallotFile, IRBallotReaderConstructor) {
  IRBallotFile test("ballot_files/ir_example.csv");

  ASSERT_EQ(test.get_type(), "IR");
  ASSERT_EQ(test.get_num_candidates(), 4);
  ASSERT_EQ(test.get_remaining(), 6);

  auto cans = test.get_candidates();

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
TEST_F(fixture_IRBallotFile, IRBallotReadergetline) {
  IRBallotFile test("ballot_files/ir_example.csv");

  ASSERT_EQ(test.get_type(), "IR");
  ASSERT_EQ(test.get_num_candidates(), 4);
  ASSERT_EQ(test.get_remaining(), 6);

  auto cans = test.get_candidates();

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

  // ASSERT_EQ(test.getline(), "");
  ASSERT_EQ(test.get_remaining(), 6);
  ASSERT_EQ(test.getline(), "1,3,4,2");
  ASSERT_EQ(test.get_remaining(), 5);
  ASSERT_EQ(test.getline(), "1,,2,");
  ASSERT_EQ(test.get_remaining(), 4);
  ASSERT_EQ(test.getline(), "1,2,3,");
  ASSERT_EQ(test.get_remaining(), 3);
  ASSERT_EQ(test.getline(), "3,2,1,4");
  ASSERT_EQ(test.get_remaining(), 2);
  ASSERT_EQ(test.getline(), ",,1,2");
  ASSERT_EQ(test.get_remaining(), 1);
  ASSERT_EQ(test.getline(), ",,,1");
  ASSERT_EQ(test.get_remaining(), 0);
}