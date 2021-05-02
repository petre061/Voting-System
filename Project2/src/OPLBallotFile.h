/**
 * @file OPLBallotFile.h
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file declares the OPLBallotFile class, a class that reads OPL
 * election data from a file
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
/**
 * @brief The OPLBallotFile class represents a ballot file for the OPL election
 *
 */
class OPLBallotFile : public BallotFile {
 protected:
  /**
   * @brief The number of candidates in the file
   */
  uint64_t num_candidates = 0;
  /**
   * @brief The number of seats to allocate as read from the file
   */
  uint64_t num_seats = 0;
  /**
   * @brief The list of candidates as read from the file
   */
  std::vector<std::pair<std::string, std::string>> candidates;
  /**
   * @brief The number of ballots left to be read from the file
   */
  uint64_t num_remaining_ballots = 0;

 public:
  /**
   * @brief Construct a new OPLBallotFile object representing the file given by
   * fname
   *
   * @param fname The name of the file to read
   */
  explicit OPLBallotFile(const std::string& fname);
  /**
   * @brief Check the file's ifstream is in a good condition
   *
   * See ifstream's good bit documentation
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
   * @brief Get the number of seats
   *
   * @return uint64_t
   */
  uint64_t get_num_seats() const { return num_seats; }
  /**
   * @brief Get the number of candidates
   *
   * @return uint64_t
   */
  uint64_t get_num_candidates() const;
  /**
   * @brief Get the number of remaining ballots
   *
   * @return uint64_t
   */
  uint64_t get_remaining() const;
  /**
   * @brief Get the candidates for the election
   *
   * @return const std::vector<std::pair<std::string, std::string>>&
   */
  const std::vector<std::pair<std::string, std::string>>& get_candidates()
      const;
  /**
   * @brief Get an auditable string representing this class
   *
   * @return std::string
   */
  std::string log() const override;
};

#endif  // PROJECT2_SRC_OPLBALLOTFILE_H_
