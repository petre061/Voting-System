/**
 * @file Ballot.h
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file declares the Ballot class which gives basic functionality to
 * different election ballot types
 * @version 1.0
 * @date 2021-03-14
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PROJECT1_SRC_BALLOT_H_
#define PROJECT1_SRC_BALLOT_H_

#include <atomic>
#include <cstdint>

#include "Loggable.h"

/**
 * @brief Base class for different ballot types.
 */
class Ballot : public Loggable {
 private:
  /**
   * A specific ballot instance's id.
   */
  uint64_t id = 0xFFFFFFFF;
  /**
   * @brief The id of the next ballot to be generated
   */
  static std::atomic<uint64_t> next_id;
  /**
   * @brief      Generate a unique id for a ballot
   *
   * This function generates a unique id by just incrementing a number. Future
   * improvements may include non-incremental generation for further security.
   *
   * @return     A unique ballot id number
   */
  static uint64_t generate_id();

 public:
  Ballot();
  /**
   * @brief      Gets the id associated with this ballot instance
   *
   * @return     The id
   */
  uint64_t get_id() const;
  /**
   * @brief      Gets the candidate choice of a ballot
   *
   * @return     The column index of a candidate
   */
  virtual uint8_t get_choice() const = 0;
  /**
   * If a ballot did not choose a candidate or is out of remaining candidates,
   * it will return @ref NO_CHOICE
   */
  static constexpr uint8_t NO_CHOICE = 0xFF;
};

#endif  // PROJECT1_SRC_BALLOT_H_
