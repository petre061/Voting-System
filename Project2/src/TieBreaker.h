/**
 * @file TieBreaker.h
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file declares a class for easily breaking ties by flipping a coin
 * @version 1.0
 * @date 2021-03-14
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PROJECT1_SRC_TIEBREAKER_H_
#define PROJECT1_SRC_TIEBREAKER_H_

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
  /**
   * @brief  Resolves a tie between num items
   *
   * @return A number between zero and (num-1) inclusive
   */
  static uint8_t resolve_tie(uint8_t num);
};

#endif  // PROJECT1_SRC_TIEBREAKER_H_
