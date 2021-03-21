// Copyright 2021 CSCI 5801 Spring 2021 Team 20

#include "test_ElectionFactory.h"

/**
 * @brief Test IR properly identified
 *
 */
TEST_F(fixture_ElectionFactory, ElectionFactoryIR) {
  Election* election = ElectionFactory::create("ballot_files/ir_example.csv");

  ASSERT_NE(election, nullptr);

  ASSERT_EQ(election->get_type(), "IR");

  delete election;
}
/**
 * @brief Test OPL properly identified
 *
 */
TEST_F(fixture_ElectionFactory, ElectionFactoryOPL) {
  Election* election = ElectionFactory::create("ballot_files/opl_example.csv");

  ASSERT_NE(election, nullptr);

  ASSERT_EQ(election->get_type(), "OPL");

  delete election;
}
/**
 * @brief Test file not found handling
 *
 */
TEST_F(fixture_ElectionFactory, ElectionFactoryNotFound) {
  Election* election = ElectionFactory::create("non_existent.csv");

  ASSERT_EQ(election, nullptr);
}
