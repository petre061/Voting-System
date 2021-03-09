// Copyright 2021 CSCI 5801 Spring 2021 Team 20
#include "AuditLog.h"
AuditLog::AuditLog(const std::string& log_name) : filename(log_name) {
  // TODO(someone): open file and get ready for writing
}
void AuditLog::log(const Loggable& item) {
  // TODO(someone): write the item into the file
}
void AuditLog::log(const std::string& text) {
  // TODO(someone): write the text into the file
}
