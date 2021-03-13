// Copyright CSCI 5801 Spring 2021 Team 20

#ifndef IRELECTION_H_
#define IRELECTION_H_

#include <cstdint>
#include <string>
#include <vector>

#include "Election.h"
#include "IRBallot.h"
#include "IRCandidate.h"
/**
 * @brief
 */
class IRElection : public Election {
 private:
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
  void redistribute(uint8_t candidate_index);
  void announce_results();

 public:
  explicit IRElection(const std::string& filename);
  int run() override;
  std::string log() const override;
};

#endif