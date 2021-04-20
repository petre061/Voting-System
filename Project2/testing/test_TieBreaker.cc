// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#include "test_TieBreaker.h"

TEST_F(fixture_TieBreaker, TieBreakerInRange) {
  uint8_t winner = 0;
  for (uint64_t i = 0; i < 100000; ++i) {
    winner = TieBreaker::resolve_tie(5);
    ASSERT_LT(winner, 5);
  }
}