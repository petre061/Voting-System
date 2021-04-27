/**
 * @file Election.h
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file defines the Election base class that has basic functionality
 * for different election types
 * @version 1.0
 * @date 2021-03-14
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PROJECT1_SRC_ELECTION_H_
#define PROJECT1_SRC_ELECTION_H_

#include <fstream>
#include <string>

#include "AuditLog.h"
#include "Loggable.h"
#include "MediaReport.h"

/**
 * @brief The Election class implements basic functionality for different
 * election types
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
  explicit Election(const std::string& election_type);
  /**
   * @brief Get the type of election
   *
   * @return const std::string& Type of election
   */
  const std::string& get_type() const;
  /**
   * @brief Abstract method to be implemented by child election classes that
   * runs the methods necessary for determining the results of the election
   */
  virtual int run() = 0;
};

#endif  // PROJECT1_SRC_ELECTION_H_
