/**
 * @file OPLBallotFactory.h
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief
 * @version 1.0
 * @date 2021-04-22
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef PROJECT2_SRC_OPLBALLOTFACTORY_H_
#define PROJECT2_SRC_OPLBALLOTFACTORY_H_
#include <fstream>
#include <string>
#include <utility>
#include <vector>

#include "Loggable.h"
#include "OPLBallot.h"
#include "OPLBallotFile.h"

class OPLBallotFactory : public Loggable {
 private:
  uint64_t total_ballots = 0;
  uint64_t ballots_remaining = 0;
  uint64_t num_seats = 0;
  std::vector<OPLBallotFile>::iterator current_file;
  std::vector<OPLBallotFile> files;
  std::vector<std::pair<std::string, std::string>> candidates;

 public:
  explicit OPLBallotFactory(const std::vector<std::string>& filenames);

  uint64_t get_remaining();
  OPLBallot get_ballot();

  uint64_t get_num_seats() const;
  const std::vector<std::pair<std::string, std::string>>& get_candiates() const;

  std::string log() const override;
};

#endif  // PROJECT2_SRC_OPLBALLOTFACTORY_H_
