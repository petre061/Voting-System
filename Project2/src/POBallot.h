// // Copyright 2021, CSCI 5801 Spring 2021 Team 20
// /**
//  * @file POBallot.h
//  * @author Andrew Petrescu (petre061@umn.edu)
//  * @brief This file declares the PO ballot class.
//  * @version 1.0
//  * @date 2021-04-25
//  *
//  * @copyright Copyright (c) 2021
//  *
//  */

// #ifndef PROJECT2_SRC_POBALLOT_H_
// #define PROJECT2_SRC_POBALLOT_H_

// #include <cstdint>
// #include <sstream>
// #include <string>

// #include "Ballot.h"

//  /**
//   * @brief A @ref Ballot for an Popularity Only election
//   */
// class POBallot : public Ballot {
// private:
// 	/**
// 	 * @brief The choice that the ballot chose.
// 	 */
// 	uint8_t choice = Ballot::NO_CHOICE;

// public:
// 	/**
// 	 * @brief Construct a new POBallot using the given line from the CSV file
// 	 *
// 	 * @param line A line from the CSV ballots file
// 	 */
// 	explicit POBallot(const std::string& line);
// 	/**
// 	 * @brief Get the index of the chosen candidate
// 	 *
// 	 * Note: May return Ballot::NO_CHOICE if the person did not choose a candidate
// 	 *
// 	 * @return uint8_t The index of the candidate
// 	 */
// 	uint8_t get_choice() const override;
// 	/**
// 	 * @brief Produce an audit log entry from an instance's data.
// 	 *
// 	 * @return std::string The audit log entry
// 	 */
// 	std::string log() const override;
// };

// #endif  // PROJECT2_SRC_POBALLOT_H_
