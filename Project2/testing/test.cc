/**
 * @file test.cc
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file is the main test runner
 * @version 1.0
 * @date 2021-03-24
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "gtest/gtest.h"

int main(int argc, char *argv[]) {
  // Initialize Tests
  ::testing::InitGoogleTest(&argc, argv);
  // Run Tests
  return RUN_ALL_TESTS();
}
