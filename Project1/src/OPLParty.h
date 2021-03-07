// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#ifndef OPLPARTY_H_
#define OPLPARTY_H_

#include <cstdint>
#include <sstream>
#include <string>
#include <queue>

#include "Loggable.h"
#include "OPLCandidate.h"

/**
 * @brief
 */
class OPLParty : public Loggable {
 private:
    std::string name;
    std::queue<OPLCandidate> candidates;
 public:
    explicit OPLParty(const std::string& name); // explicit keyword prevents compiler from using constructor for implicit conversion which can hide bugs
    uint64_t get_tally();
    std::string log() const override;
};

#endif  // OPLPARTY_H_