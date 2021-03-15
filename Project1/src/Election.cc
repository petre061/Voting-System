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

Election::Election(const std::string& election_type, const std::string& ballots)
    : type(election_type),
      ballot_filename(ballots),
      ballot_file(ballot_filename),
      audit_log("audit_log_" + type + "_" + make_file_date() + ".txt"),
      media_report("media_report_" + type + "_" + make_file_date() + ".txt") {
  // Unable to open file specified, throw exception
  if (!ballot_file.is_open()) {
    throw std::invalid_argument("Unable to open ballot file \'" +
                                ballot_filename + "\'");
  }
}

Election::~Election() {
  // Force closure of ballot_file on destruction
  if (ballot_file.is_open()) {
    ballot_file.close();
  }
}
