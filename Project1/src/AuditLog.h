// Copyright 2021 CSCI 5801 Spring 2021 Team 20

#ifndef PROJECT1_SRC_AUDITLOG_H_
#define PROJECT1_SRC_AUDITLOG_H_

#include <chrono>  // NOLINT[build/c++11]
#include <ctime>
#include <fstream>
#include <string>

#include "Loggable.h"
/**
 * @brief
 */
class AuditLog {
 private:
  std::string filename;
  std::ofstream file;
  static std::string get_time_date();

 public:
  explicit AuditLog(const std::string& log_name);
  ~AuditLog();
  void log(const Loggable& item);
  void log(const std::string& text);
};

#endif  // PROJECT1_SRC_AUDITLOG_H_
