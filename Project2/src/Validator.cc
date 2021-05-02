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

#include "Validator.h"

#include <cmath>
#include <iostream>

/**
 * @brief A single instance of the validator class
 *
 * This is used to provide a singleton instance to classes that need a shared
 * instance
 */
Validator Validator::instance;
/**
 * @brief
 *
 * @param num_choices
 * @param total_candidates
 * @return true if the the number of choices on a ballot is greater than half of
 * the total number of candidates possible, meaning that the ballot is valid
 * @return false if the ballot is invalid
 */
bool Validator::validate(uint8_t num_choices, uint8_t total_candidates) {
  uint8_t more_than_half = round(total_candidates / 2);
  return (num_choices >= more_than_half);
}
