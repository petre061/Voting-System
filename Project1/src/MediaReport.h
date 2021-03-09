// Copyright 2021 CSCI 5801 Spring 2021 Team 20

#ifndef PROJECT1_SRC_MEDIAREPORT_H_
#define PROJECT1_SRC_MEDIAREPORT_H_

#include <fstream>
#include <string>
/**
 * @brief
 */
class MediaReport {
 private:
  std::string filename;
  std::ofstream file;

 public:
  explicit MediaReport(const std::string& report_name);
  void write(const std::string& text);
};

#endif  // PROJECT1_SRC_MEDIAREPORT_H_
