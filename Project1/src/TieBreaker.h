// Copyright CSCI 5801 Spring 2021 Team 20

#ifndef TIEBREAKER_H_
#define TIEBREAKER_H_

#include <random>
/**
 * @brief      This class describes a tie breaker.
 */
class TieBreaker {
 private:
  /**
   * The random device of the computer
   */
  std::random_device device;
  /**
   * A pseudo-random number generator
   */
  std::mt19937 twister;
  /**
   * A uniform distribution of 0 and 1
   */
  std::uniform_int_distribution<std::mt19937::result_type> distribution;
  /**
   * @brief      Constructs a new private instance
   *
   * Note: This is purposly private in order to follow the singleton design
   * pattern
   */
  TieBreaker() : twister(device()), distribution(0, 1) {}
  /**
   * The singleton instance
   */
  static TieBreaker instance;

 public:
  /**
   * @brief      Get a random coin flip
   *
   * @return     A true/false value representing the coin.
   */
  static bool flip();
};

#endif  // TIEBREAKER_H_
