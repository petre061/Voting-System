// Copyright 2021 CSCI 5801 Spring 2021 Team 20
#include "AuditLog.h"

#include <stdexcept>

AuditLog::AuditLog(const std::string& log_name)
    : filename(log_name), file(filename) {
  // TODO(someone): open file and get ready for writing

  // Unable to open file specified, throw exception
  if (!file.is_open()) {
    throw std::invalid_argument("Unable to create AuditLog \'" + filename +
                                "\'");
  }

  // Write audit log header
  file << "Voting System 1.0" << std::endl;
  file << "Log Start: " << get_time_date() << std::endl;
}
AuditLog::~AuditLog() {
  file << "Log End: " << get_time_date() << std::endl;
  file.close();
}
void AuditLog::log(const Loggable& item) {
  // Write the item into the file
  file << item.log() << std::endl;
}
void AuditLog::log(const std::string& text) {
  // Write the text into the file
  file << text << std::endl;
}
std::string AuditLog::get_time_date() {
  // Return the current time as a string
  auto now =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  return std::ctime(&now);
}
