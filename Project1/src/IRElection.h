// Copyright CSCI 5801 Spring 2021 Team 20

#ifndef IRELECTION_H_
#define IRELECTION_H_

#include <cstdint>
#include <string>
#include <vector>

#include "Election.h"
#include "IRBallot.h"
#include "IRCandidate.h"
#include "TieBreaker.h"

/**
 * @brief
 */
class IRElection : public Election {
 private:
  /**
   * @brief Int to store the index of the winning candidate
   */
  int winnerIndex;
  /**
   * @brief List that stores all indicies of a max tally, used for tie breaking
   * in winner case
   */
  std::vector<int> max_indicies;
  /**
   * @brief List that stores all indicies of a min tally, used for tie breaking
   * in loser (redistribute) case
   */
  std::vector<int> min_indicies;
  /**
   * @brief The candidates in the election
   */
  std::vector<IRCandidate> candidates;
  /**
   * @brief Parse the ballots from the file
   *
   * After the ballots file header has been parsed, go line by line through the
   * remaining ballots and add them to the appropriate candidate.
   */
  void parse_ballots();
  /**
   * @brief Redistributes the ballots of a candidate who has been eliminated
   * from the running
   *
   * @param candidate_index The index location of the candidate who has been
   * eliminated
   */
  void redistribute(uint8_t candidate_index);
  /**
   * @brief Prints to screen, media file, and audit log all necessary
   * information about the results of the election
   */
  void announce_results();
  /**
   * @brief Finds all instances of the highest tally in a given list of
   * candidate tallies
   *
   * @param tallies A list of candidate tallies
   * @param max The max tally number we are searching for in the list
   */
  void find_max_values(uint64_t max);
  /**
   * @brief Finds all instances of the lowest tally in a given list of candidate
   * tallies
   *
   * @param tallies A list of candidate tallies
   * @param min The min tally number we are searching for in the list
   */
  void find_min_values(uint64_t min);

 public:
  /**
   * @brief Constructor for IR Election object
   */
  explicit IRElection(const std::string& filename);
  /**
   * @brief Run an IR Election
   */
  int run() override;
  /**
   * @brief Log pertinent election information to the log file
   */
  std::string log() const override;
};

#endif