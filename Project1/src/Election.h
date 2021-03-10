// Copyright CSCI 5801 Spring 2021 Team 20

#ifndef ELECTION_H_
#define ELECTION_H_

#include <fstream>
#include <string>

#include "AuditLog.h"
#include "Loggable.h"
#include "MediaReport.h"

/**
 * @brief
 */
class Election : public Loggable {
 protected:
  std::string type = "UNKNOWN ELECTION TYPE";

  std::string ballot_filename;
  std::ifstream ballot_file;

  AuditLog audit_log;
  MediaReport media_report;

  uint64_t total_ballots = 0;

 public:
  explicit Election(const std::string& election_type,
                    const std::string& ballots);
  virtual ~Election();
  virtual int run() = 0;
};

#endif