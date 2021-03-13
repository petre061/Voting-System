// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#ifndef PROJECT1_TESTING_TEST_MEDIAREPORT_H_
#define PROJECT1_TESTING_TEST_MEDIAREPORT_H_

#include "MediaReport.h"
#include "gtest/gtest.h"

class fixture_MediaReport : public ::testing::Test {
 protected:
  MediaReport* report = nullptr;

 public:
  void SetUp() {
    // Remove any previous instances
    delete report;
    report = nullptr;
  }

  void TearDown() {
    // Delete report if we haven't cleaned it up
    delete report;
    report = nullptr;
  }
};
#endif  // PROJECT1_TESTING_TEST_MEDIAREPORT_H_
