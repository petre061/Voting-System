#include "gtest/gtest.h"

int main(int argc, char *argv[]) {
  // Initialize Tests
  ::testing::InitGoogleTest(&argc, argv);
  // Run Tests
  return RUN_ALL_TESTS();
}
