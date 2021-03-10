
// Copyright CSCI 5801 Spring 2021 Team 20

#include "Election.h"

#include "AuditLog.h"
#include "MediaReport.h"

Election::Election(const std::string& election_type, const std::string& ballots)
    : type(election_type),
      ballot_filename(ballots),
      ballot_file(ballot_filename),
      audit_log("audit_log_" + type + "_" + "<TODO: date>" + ".txt"),
      media_report("media_report_" + type + "_" + "<TODO:date>" + ".txt") {
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
