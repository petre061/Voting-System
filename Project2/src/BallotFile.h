/**
 * @file BallotFile.h
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file declares the BallotFile class
 * @version 1.0
 * @date 2021-04-21
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef PROJECT2_SRC_BALLOTFILE_H_
#define PROJECT2_SRC_BALLOTFILE_H_
#include <fstream>
#include <string>
#include <vector>

#include "Loggable.h"
/**
 * @brief The BallotFile class defines an abstract base class that represents a
 * file containing ballots
 *
 */
class BallotFile : public Loggable {
 protected:
  /**
   * @brief The name of the ballot file
   *
   */
  std::string filename;
  /**
   * @brief The actual file stream of the file specified by filename
   *
   */
  std::ifstream file;

  /**
   * @brief The type of ballot file
   *
   */
  std::string type = "UNKNOWN BALLOT TYPE";
  /**
   * @brief The number of ballots in the ballot file
   *
   */
  uint64_t num_ballots = 0;

 public:
  explicit BallotFile(const std::string& fname);
  /**
   * @brief Get a ballot line from the ballot file
   *
   * @return std::string
   */
  virtual std::string getline() = 0;
  /**
   * @brief Get the number of ballots in the file
   *
   * @return uint64_t
   */
  uint64_t get_num_ballots() const;
  /**
   * @brief Get the number of remaining ballots
   *
   * @return uint64_t
   */
  virtual uint64_t get_remaining() const = 0;
  /**
   * @brief Get the type of ballot file
   *
   * @return const std::string&
   */
  const std::string& get_type() const;
};

#endif  // PROJECT2_SRC_BALLOTFILE_H_
