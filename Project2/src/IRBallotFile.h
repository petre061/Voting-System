/**
 * @file IRBallotFile.h
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file declares the IRBallotFile class
 * @version 1.0
 * @date 2021-04-21
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef PROJECT2_SRC_IRBALLOTFILE_H_
#define PROJECT2_SRC_IRBALLOTFILE_H_
#include <fstream>
#include <map>
#include <string>
#include <utility>
#include <vector>

#include "BallotFile.h"
/**
 * @brief This file implements a BallotFile for the IR voting format
 *
 */
class IRBallotFile : public BallotFile {
 protected:
  /**
   * @brief The number of candidates in the election
   *
   */
  uint64_t num_candidates = 0;

  /**
   * @brief The list of candidates and their party names
   *
   * Each pair is formatted like this:
   * <candidate_name, party_name>
   */
  std::vector<std::pair<std::string, std::string>> candidates;

  /**
   * @brief The number of unread ballots remaining in the file
   *
   */
  uint64_t num_remaining_ballots = 0;

 public:
  /**
   * @brief Construct a new IRBallotFile object that parses the specified file
   *
   * @param fname The name of the file to read ballots from
   */
  explicit IRBallotFile(const std::string& fname);
  /**
   * @brief Check that the file is good
   *
   * See ifstream's good bit for more information
   *
   * @return true File is in a good state
   * @return false File is in a bad state
   */
  bool good() const;
  /**
   * @brief Get a line representing a ballot from the file
   *
   * @return std::string
   */
  std::string getline() override;
  /**
   * @brief Get the number of candidates
   *
   * @return uint64_t
   */
  uint64_t get_num_candidates() const;
  /**
   * @brief Get the remaining number of ballots
   *
   * @return uint64_t
   */
  uint64_t get_remaining() const;
  /**
   * @brief Get the list of candidates parsed from the file
   *
   * @return const std::vector<std::pair<std::string, std::string>>&
   */
  const std::vector<std::pair<std::string, std::string>>& get_candidates()
      const;
  /**
   * @brief Get an auditable string representing this file
   *
   * @return std::string
   */
  std::string log() const override;
};

#endif  // PROJECT2_SRC_IRBALLOTFILE_H_
