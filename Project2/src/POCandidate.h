/**
 * @file POCandidate.h
 * @author Andrew Petrescu (petre061@umn.edu)
 * @brief This file declares the PO Candidate class.
 * @version 1.0
 * @date 2021-04-25
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef POCANDIDATE_H_
#define POCANDIDATE_H_

#include <cstdint>
#include <queue>
#include <sstream>
#include <string>

#include "Loggable.h"
#include "POBallot.h"

 /**
  * @brief
  */
class POCandidate : public Loggable {
private:
	std::string name;
	std::queue<POBallot> ballots;

public:
	/**
	 * @brief Construct a new POCandidate object
	 *
	 * @param candidate
	 */
	explicit POCandidate(const std::string& candidate); // explicit keyword prevents compiler from using constructor for implicit conversion which can hide bugs
  /**
   * @brief Add a ballot
   *
   * @return void
   */
	void add_ballot(POBallot new_ballot);

	/**
	 * @brief Get the tally object
	 *
	 * @return uint64_t
	 */
	uint64_t get_tally();
	/**
	 * @brief
	 *
	 * @return std::string
	 */
	std::string log() const override;
	/**
	* @return The name of the candidate
	*/
	const std::string& get_name() const;
};

#endif  // POCANDIDATE_H_