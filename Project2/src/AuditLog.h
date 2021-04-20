/**
 * @file AuditLog.h
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file declares the AuditLog class.
 * @version 1.0
 * @date 2021-03-14
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PROJECT1_SRC_AUDITLOG_H_
#define PROJECT1_SRC_AUDITLOG_H_

#include <chrono>  // NOLINT[build/c++11]
#include <ctime>
#include <fstream>
#include <string>

#include "Loggable.h"
/**
 * @brief Create an audit log
 *
 * The @ref AuditLog class handles writing various strings and objects into a
 * file in order to create an audit log. It relies on other classes to determine
 * when it is appropriate to log an action.
 *
 */
class AuditLog {
 private:
  /**
   * @brief The filename of the audit log
   */
  std::string filename;
  /**
   * @brief The file stream for the audit log
   */
  std::ofstream file;
  /**
   * @brief Get a time and date string for the current time
   */
  static std::string get_time_date();

 public:
  /**
   * @brief Create an audit log at @ref log_name
   */
  explicit AuditLog(const std::string& log_name);
  /**
   * @brief Finish up the audit log
   *
   * This involves writing a finish time and closing the file
   */
  ~AuditLog();
  /**
   * @brief Write a line to the audit log using the @ref Loggable::log()
   * function
   */
  void log(const Loggable& item);
  /**
   * @brief Write a line to the audit log with @ref text as the contents
   */
  void log(const std::string& text);
};

#endif  // PROJECT1_SRC_AUDITLOG_H_
