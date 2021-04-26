/**
 * @file OPLBallotFile.h
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file declares the IRBallotFile class
 * @version 1.0
 * @date 2021-04-21
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef PROJECT2_SRC_OPLBALLOTFILE_H_
#define PROJECT2_SRC_OPLBALLOTFILE_H_
#include <fstream>
#include <map>
#include <string>
#include <utility>
#include <vector>

#include "BallotFile.h"

class OPLBallotFile : public BallotFile {
 protected:
  uint64_t num_candidates = 0;
  uint64_t num_seats = 0;

  std::vector<std::pair<std::string, std::string>> candidates;

  uint64_t num_remaining_ballots = 0;

 public:
  explicit OPLBallotFile(const std::string& fname);

  bool good() const;
  std::string getline() override;

  uint64_t get_num_seats() const { return num_seats; }
  uint64_t get_num_candidates() const;
  uint64_t get_remaining() const;

  const std::vector<std::pair<std::string, std::string>>& get_candidates()
      const;

  std::string log() const override;
};

#endif  // PROJECT2_SRC_OPLBALLOTFILE_H_