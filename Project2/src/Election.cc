/**
 * @file Election.cc
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file implements basic Election functionality
 * @version 1.0
 * @date 2021-03-14
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "Election.h"

#include "AuditLog.h"
#include "MediaReport.h"

std::string Election::make_file_date() {
  // Get the local time
  auto now =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  std::tm tm = *std::localtime(&now);
  // Set up a buffer for time string formatting
  char time_buffer[] = "YYYY_mm_dd_HH_MM_SS";
  // Format the time and place into time buffer
  std::strftime(time_buffer, sizeof(time_buffer), "%Y_%m_%d_%H_%M_%S", &tm);
  // Return a std::string from our c string
  return std::string(time_buffer);
}

Election::Election(const std::string& election_type)
    : type(election_type),
      audit_log("audit_log_" + type + "_" + make_file_date() + ".txt"),
      media_report("media_report_" + type + "_" + make_file_date() + ".txt") {
  // Nothing to do
}
const std::string& Election::get_type() const {
  // Return the election type
  return type;
}
