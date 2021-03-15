/**
 * @file MediaReport.h
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file declares a class for easily creating media reports from an
 * election
 * @version 1.0
 * @date 2021-03-14
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PROJECT1_SRC_MEDIAREPORT_H_
#define PROJECT1_SRC_MEDIAREPORT_H_

#include <chrono>  // NOLINT[build/c++11]
#include <ctime>
#include <fstream>
#include <string>
/**
 * @brief A class representing a media report
 *
 * This class manages a press report file for the voting system.
 */
class MediaReport {
 private:
  /**
   * @brief The filename for the media report
   */
  std::string filename;
  /**
   * @brief The ouput file stream for the media report
   */
  std::ofstream file;
  /**
   * @brief Get the current time and date as a string
   */
  static std::string get_time_date();

 public:
  /**
   * @brief Create a new @ref MediaReport at @ref report_name
   *
   * This will throw @ref std::invalid_argument if the specified report cannot
   * be created
   */
  explicit MediaReport(const std::string& report_name);
  /**
   * @brief Write a line to the MediaReport containing @ref text
   */
  void write(const std::string& text);
};

#endif  // PROJECT1_SRC_MEDIAREPORT_H_
