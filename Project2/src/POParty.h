// Copyright 2021, CSCI 5801 Spring 2021 Team 20
/**
 * @file POElection.cc
 * @author Andrew Petrescu (petre061@umn.edu)
 * @brief This file declares the PO Party class.
 * @version 1.0
 * @date 2021-04-28
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef POPARTY_H_
#define POPARTY_H_

#include <cstdint>
#include <queue>
#include <sstream>
#include <string>

#include "Loggable.h"
#include "POCandidate.h"
#include "TieBreaker.h"

 /**
  * @brief
  */
class POParty : public Loggable {
private:
    std::string pname;
    std::vector<POCandidate*> candidates;

public:
    /**
     * @brief Construct a new POParty object
     *
     * @param name
     */
    explicit POParty(
        const std::string&
        name);
    /**
     * @brief Get the tally object
     *
     * @return uint64_t
     */
    uint64_t get_tally();
    /**
     * @brief
     *
     * @param new_candidate
     */
    void add_candidate(POCandidate* new_candidate);
    /**
     * @brief
     *
     * @return std::string
     */
    std::string log() const override;
    /**
     * @brief Get the name object
     *
     * @return std::string
     */
    std::string get_name();
    /**
     * @brief Get the top n candidate names
     *
     * @param n
     * @return std::vector<std::string>
     */
    std::vector<std::string> get_top_n_candidate_names(int n);
    /**
     * @brief Get the candidates vector
     *
     * @return std::vector<POCandidate*>
     */
    std::vector<POCandidate*> get_candidates();
};

#endif  // POPARTY_H_