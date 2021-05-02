/**
 * @file Validation.h
 * @author Peter Linden // linde764
 * @brief This file implements a class meant to verify that each ballot in an
 * IRV election is valid
 * @version 0.1
 * @date 2021-04-26
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <stdint.h>
#ifndef PROJECT2_SRC_VALIDATOR_H_
#define PROJECT2_SRC_VALIDATOR_H_

class Validator {
 private:
  static Validator instance;

 public:
  /**
   * @brief Validate a IR vote based on the number of choices and number of
   * candidates
   *
   * @param num_choices
   * @param total_candidates
   * @return true
   * @return false
   */
  static bool validate(uint8_t num_choices, uint8_t total_candidates);
};

#endif  // PROJECT2_SRC_VALIDATOR_H_
