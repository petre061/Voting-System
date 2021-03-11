// Copyright CSCI 5801 Spring 2021 Team 20

#ifndef PROJECT1_SRC_ELECTION_H_
#define PROJECT1_SRC_ELECTION_H_

#include <fstream>
#include <string>

#include "AuditLog.h"
#include "Loggable.h"
#include "MediaReport.h"

/**
 * @brief
 */
class Election : public Loggable {
 private:
  /**
   * @brief Make a string with the date seperated by underscores
   */
  static std::string make_file_date();

 protected:
  /**
   * @brief The type of election.
   */
  std::string type = "UNKNOWN ELECTION TYPE";

  /**
   * @brief The name of the file that holds the ballots.
   */
  std::string ballot_filename;
  /**
   * @brief The actual file handler for the ballot file.
   */
  std::ifstream ballot_file;
  /**
   * @brief The @ref AuditLog instance for an election.
   */
  AuditLog audit_log;
  /**
   * @brief The @ref MediaReport instance for an election.
   */
  MediaReport media_report;
  /**
   * @brief The total number of ballots contained in the ballots file.
   */
  uint64_t total_ballots = 0;

 public:
  /**
   * @brief Start an election setting the type and opening the ballots file
   *
   * This must be called in the initializer list of the inheriting type's
   * constructor.
   */
  explicit Election(const std::string& election_type,
                    const std::string& ballots);
  virtual ~Election();
  virtual int run() = 0;
};

#endif  // PROJECT1_SRC_ELECTION_H_
