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
TEST_F(fixture_IRBallotFile, getline) {
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
TEST_F(fixture_IRBallotFile, file_not_found) {
  IRBallotFile test("ballot_files/ir_nonexist.csv");

  ASSERT_EQ(test.good(), false);
}
TEST_F(fixture_IRBallotFile, get_candidates) {
  IRBallotFile test("ballot_files/ir_example.csv");

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
TEST_F(fixture_IRBallotFile, log) {
  const std::string filename = "ballot_files/ir_example.csv";

  IRBallotFile test(filename);

  // ASSERT_NE(test.log().find(""), std::string::npos);

  ASSERT_NE(test.log().find(filename), std::string::npos)
      << "Filename must appear in log";

  ASSERT_NE(test.log().find("4"), std::string::npos)
      << "Log must contain the number of candidates";

  ASSERT_NE(test.log().find("6"), std::string::npos)
      << "Log must contain the number of ballots";

  // Make sure the candidates and parties are in the log
  ASSERT_NE(test.log().find("Rosen (D)"), std::string::npos)
      << "Candidate missing from log";
  ASSERT_NE(test.log().find("Kleinberg (R)"), std::string::npos)
      << "Candidate missing from log";
  ASSERT_NE(test.log().find("Chou (I)"), std::string::npos)
      << "Candidate missing from log";
  ASSERT_NE(test.log().find("Royce (L)"), std::string::npos)
      << "Candidate missing from log";
}
