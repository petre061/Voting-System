/**
 * @file OPLBallotFactory.h
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This class defines the OPLBallotFactory class, which reads in OPL
 * ballots from a list of files
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
/**
 * @brief The OPLBallotFactory class reads in OPLBallots from a list of OPL
 * ballot files
 */
class OPLBallotFactory : public Loggable {
 private:
  /**
   * @brief The total ballots contained in all the specified files
   */
  uint64_t total_ballots = 0;
  /**
   * @brief The number of ballots remaining to be read
   */
  uint64_t ballots_remaining = 0;
  /**
   * @brief The number of seats in the election
   *
   */
  uint64_t num_seats = 0;
  /**
   * @brief An iterator to the current file to read ballots from
   */
  std::vector<OPLBallotFile>::iterator current_file;
  /**
   * @brief The list of files to read ballots from
   *
   */
  std::vector<OPLBallotFile> files;
  /**
   * @brief The list of candidates for the election
   *
   */
  std::vector<std::pair<std::string, std::string>> candidates;

 public:
  /**
   * @brief Construct a new OPLBallotFactory object
   *
   * @param filenames The list of files to read election data from
   */
  explicit OPLBallotFactory(const std::vector<std::string>& filenames);
  /**
   * @brief Get the number of remaining ballots
   *
   * @return uint64_t
   */
  uint64_t get_remaining() const;
  /**
   * @brief Get a ballot from the files
   *
   * @return OPLBallot
   */
  OPLBallot get_ballot();
  /**
   * @brief Get the number of seats in the election
   *
   * @return uint64_t
   */
  uint64_t get_num_seats() const;
  /**
   * @brief Get the candidates for the election
   *
   * @return const std::vector<std::pair<std::string, std::string>>&
   */
  const std::vector<std::pair<std::string, std::string>>& get_candidates()
      const;
  /**
   * @brief Create an auditable string for this class
   *
   * @return std::string
   */
  std::string log() const override;
};

#endif  // PROJECT2_SRC_OPLBALLOTFACTORY_H_
