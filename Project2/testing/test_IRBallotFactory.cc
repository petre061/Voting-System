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

#include "IRBallotFactory.h"

TEST_F(fixture_IRBallotFactory, IRBallotFactoryConstructor) {
  IRBallotFactory factory(
      {"ballot_files/ir_half_first.csv", "ballot_files/ir_half_second.csv"});

  ASSERT_EQ(factory.get_remaining(), 36);
}
TEST_F(fixture_IRBallotFactory, IRBallotFactory_get_ballot) {
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
  b = factory.get_ballot();
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

TEST_F(fixture_IRBallotFactory, IRBallotFactory_get_candidates) {
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
