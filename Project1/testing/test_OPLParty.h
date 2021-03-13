<<<<<<< HEAD
// Copyright CSCI 5801 Spring 2021 Team 20
=======
// Copyright 2021, CSCI 5801 Spring 2021 Team 20
>>>>>>> e992fd7d1217d659013211d0c43cfcae66cad3e4

#ifndef PROJECT1_TESTING_TEST_OPLPARTY_H_
#define PROJECT1_TESTING_TEST_OPLPARTY_H_

#include "OPLParty.h"
#include "gtest/gtest.h"

class fixture_OPLParty : public ::testing::Test {
 protected:
  OPLParty* party = nullptr;

 public:
  void SetUp() {
    // Remove any previous instances
    delete party;
    party = nullptr;
  }

  void TearDown() {
<<<<<<< HEAD
    // Delete ballot if we haven't cleaned it up
    delete party;
  }
};
#endif  // PROJECT1_TESTING_TEST_OPLPARTY_H_
=======
    // Delete report if we haven't cleaned it up
    delete party;
    party = nullptr;
  }
};
#endif  // PROJECT1_TESTING_TEST_OPLPARTY_H_
>>>>>>> e992fd7d1217d659013211d0c43cfcae66cad3e4
