// Copyright CSCI 5801 Spring 2021 Team 20

#ifndef LOGGABLE_H_
#define LOGGABLE_H_

#include <sstream>
#include <string>

/**
 * @brief
 */
class Loggable {
 public:
  virtual std::string log() const = 0;
};

#endif  // LOGGABLE_H_
