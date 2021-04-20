/**
 * @file Loggable.h
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file declares an interface to make inherting classes loggable
 * with the AuditLog class
 * @version 1.0
 * @date 2021-03-14
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PROJECT1_SRC_LOGGABLE_H_
#define PROJECT1_SRC_LOGGABLE_H_

#include <sstream>
#include <string>

/**
 * @brief Loggable provides a simple method for classes to produce an audit log
 * entry
 *
 * The methods from this class are used in the AuditLog::log method to write
 * class information to the log.
 */
class Loggable {
 public:
  /**
   * @brief Make a string containing important information for an audit log
   *
   * @return std::string
   */
  virtual std::string log() const = 0;
};

#endif  // PROJECT1_SRC_LOGGABLE_H_
