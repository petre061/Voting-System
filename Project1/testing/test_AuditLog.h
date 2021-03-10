// Copyright CSCI 5801 Spring 2021 Team 20

#ifndef PROJECT1_TESTING_TEST_AUDITLOG_H_
#define PROJECT1_TESTING_TEST_AUDITLOG_H_

#include "AuditLog.h"
#include "gtest/gtest.h"

class fixture_AuditLog : public ::testing::Test {
 protected:
  AuditLog* log = nullptr;

 public:
  void SetUp() {
    // Remove any previous instances
    delete log;
    log = nullptr;
  }

  void TearDown() {
    // Delete log if we haven't cleaned it up
    delete log;
  }
};
#endif  // PROJECT1_TESTING_TEST_AUDITLOG_H_
