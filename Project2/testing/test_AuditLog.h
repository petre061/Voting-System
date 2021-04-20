// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#ifndef PROJECT1_TESTING_TEST_AUDITLOG_H_
#define PROJECT1_TESTING_TEST_AUDITLOG_H_

#include "AuditLog.h"
#include "gtest/gtest.h"

class fixture_AuditLog : public ::testing::Test {
 protected:
 public:
  void SetUp() {
    // Set up any data for the test
  }

  void TearDown() {
    // Clean up any data from the test
  }
};
#endif  // PROJECT1_TESTING_TEST_AUDITLOG_H_
