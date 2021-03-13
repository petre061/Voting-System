// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#ifndef PROJECT1_SRC_IRCANDIDATE_H_
#define PROJECT1_SRC_IRCANDIDATE_H_

#include <cstdint>
#include <queue>
#include <string>

#include "IRBallot.h"
#include "Loggable.h"

/**
 * @brief An Independent Runoff Candidate
 */
class IRCandidate : public Loggable {
 private:
  /**
   * @brief The name of a candidate
   */
  std::string name;
  /**
   * @brief The name of a candidate's party
   */
  std::string party;
  /**
   * @brief The ballots a candidate has received
   */
  std::queue<IRBallot> ballots;
  /**
   * @brief Whether or not a candidate has been eliminated
   */
  bool eliminated = false;

 public:
  /**
   * @brief Construct a new Independent Runoff candidate
   */
  IRCandidate(const std::string& candidate_name,
              const std::string& candidate_party);
  /**
   * @brief Add a ballot to a candidate
   *
   * This method assumes that the new_ballot is designated for this candidate.
   */
  void add_ballot(IRBallot new_ballot);
  /**
   * @brief Get the total number of ballots for a candidate.
   */
  uint64_t get_tally() const;
  /**
   * @brief Get the ballots from this candidate
   *
   * This method is to be used during redistribution of votes.
   */
  const std::queue<IRBallot>& get_ballots() const;
  /**
   * @brief Mark a candidate as eliminated
   */
  void eliminate();
  /**
   * @brief Check if the candidate has been eliminated
   *
   * @return A truthy value if the candidate has been eliminated, false
   * otherwise.
   */
  bool get_eliminated() const;
  /**
   * @return The name of the candidate
   */
  const std::string& get_name() const;
  /**
   * @return The name of the candidate's party
   */
  const std::string& get_party() const;
  /**
   * @brief Convert the candidate's data into a string suitable for logging
   */
  std::string log() const override;
};

#endif  // PROJECT1_SRC_IRCANDIDATE_H_
