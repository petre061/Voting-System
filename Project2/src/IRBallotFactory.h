/**
 * @file IRBallotFactory.h
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief
 * @version 1.0
 * @date 2021-04-22
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef PROJECT2_SRC_IRBALLOTFACTORY_H_
#define PROJECT2_SRC_IRBALLOTFACTORY_H_
#include <fstream>
#include <string>
#include <utility>
#include <vector>

#include "IRBallot.h"
#include "IRBallotFile.h"
#include "Loggable.h"

class IRBallotFactory : public Loggable {
 private:
  uint64_t total_ballots = 0;
  uint64_t ballots_remaining = 0;
  std::vector<IRBallotFile>::iterator current_file;
  std::vector<IRBallotFile> files;
  std::vector<std::pair<std::string, std::string>> candidates;

 public:
  explicit IRBallotFactory(const std::vector<std::string>& filenames);

  uint64_t get_remaining() const;
  IRBallot get_ballot();

  const std::vector<std::pair<std::string, std::string>>& get_candiates() const;

  std::string log() const override;
};

#endif  // PROJECT2_SRC_IRBALLOTFACTORY_H_
