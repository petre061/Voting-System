/**
 * @file IRBallot.h
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file declares a ballot for an Independant Runoff election
 * @version 1.0
 * @date 2021-03-14
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PROJECT1_SRC_IRBALLOT_H_
#define PROJECT1_SRC_IRBALLOT_H_

#include <cstdint>
#include <string>
#include <utility>
#include <vector>

#include "Ballot.h"

/**
 * @brief This class represents an Independent Runoff election ballot.
 */
class IRBallot : public Ballot {
 private:
  /**
   * @brief A list of candidate indices in order of preference.
   *
   * This is accessed through @ref get_choice() and the next choice is selected
   * with @ref increment_choice()
   */
  std::vector<uint8_t> choices;
  /**
   * @brief The index of the current choice
   *
   */
  uint8_t choice_index = 0;
  /**
   * @brief A sorter that sorts candidate index by preference
   *
   */
  static bool choice_sorter(const std::pair<uint8_t, uint8_t>& a,
                            const std::pair<uint8_t, uint8_t>& b);

 public:
  /**
   * @brief      Constructs a new Independent Runoff ballot from a csv file line
   *
   * @param[in]  line  A line from the CSV ballot file
   */
  explicit IRBallot(const std::string& line);
  /**
   * @brief      Gets the index of the preferred candidate.
   *
   * This method gets the index of a candidate based on the candidate ranking
   * and whether this ballot has been redistributed with @ref
   * increment_choice().
   *
   * This method may return NO_CHOICE if the ballot is out
   * of candidate choices or the ballot never chose an initial candidate.
   *
   * @return     The index of a candidate
   */
  uint8_t get_choice() const override;
  /**
   * @brief Increment the candidate choice
   *
   * This is used when a ballot is redistributed to a different candidate. This
   * will make it so that @ref get_choice() will return the next preferred
   * candidate.
   */
  void increment_choice();
  /**
   * @brief      Create a string representing this ballot for logging
   *
   * This method will generate, then return a string that can be written to a
   * log in order to provide audit logging capabilities.
   *
   * @return     A string appropriate for logging
   */
  std::string log() const override;
  /**
   * @brief      Gets a reference to the vector of choices
   *
   * This is mainly used for testing to read the internal data structure
   */
  const std::vector<uint8_t>& get_choices() const;
};

#endif  // PROJECT1_SRC_IRBALLOT_H_
