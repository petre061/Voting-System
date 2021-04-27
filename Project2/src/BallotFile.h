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

class BallotFile : public Loggable {
 protected:
  std::string filename;
  std::ifstream file;

  std::string type = "UNKNOWN BALLOT TYPE";
  uint64_t num_ballots = 0;

 public:
  explicit BallotFile(const std::string& fname);

  virtual std::string getline() = 0;
  uint64_t get_num_ballots() const;
  virtual uint64_t get_remaining() const = 0;
  const std::string& get_type() const;
};

#endif  // PROJECT2_SRC_BALLOTFILE_H_
