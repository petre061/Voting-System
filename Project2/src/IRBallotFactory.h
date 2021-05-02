/**
 * @file IRBallotFactory.h
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file defines the IRBallotFactory, a class that produces IRBallots
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
/**
 * @brief The IRBallotFactory class produces IRBallots from a list of filenames
 *
 */
class IRBallotFactory : public Loggable {
 private:
  /**
   * @brief The total number of ballots from all the files
   *
   */
  uint64_t total_ballots = 0;
  /**
   * @brief The number of ballots remaining to be read
   *
   */
  uint64_t ballots_remaining = 0;
  /**
   * @brief An iterator pointing to the IRBallotFile that we are currently
   * reading ballot from
   *
   */
  std::vector<IRBallotFile>::iterator current_file;
  /**
   * @brief A list of IRBallotFiles to pull candidates and ballots from
   *
   */
  std::vector<IRBallotFile> files;
  /**
   * @brief A list of candidates gotten from the IRBallotFile list
   *
   */
  std::vector<std::pair<std::string, std::string>> candidates;

 public:
  /**
   * @brief Construct a new IRBallotFactory object from a list of filenames
   *
   * @param filenames A list of files containing IR election data
   */
  explicit IRBallotFactory(const std::vector<std::string>& filenames);
  /**
   * @brief Get the remaining number of ballots
   *
   * @return uint64_t
   */
  uint64_t get_remaining() const;
  /**
   * @brief Get a ballot
   *
   * @return IRBallot
   *
   * This method will try to get a IRBallot from the list of files.
   */
  IRBallot get_ballot();

  /**
   * @brief Get the list of candidates for the election
   *
   * @return const std::vector<std::pair<std::string, std::string>>&
   */
  const std::vector<std::pair<std::string, std::string>>& get_candiates() const;

  /**
   * @brief Create an auditable string for this class
   *
   * @return std::string
   */
  std::string log() const override;
};

#endif  // PROJECT2_SRC_IRBALLOTFACTORY_H_
