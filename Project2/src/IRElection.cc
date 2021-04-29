/**
 * @file IRElection.cc
 * @author Nikhil Srikanth (srika018@umn.edu)
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file declares an Independent Runoff election class
 * @version 1.0
 * @date 2021-03-14
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "IRElection.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>

#include "Ballot.h"

IRElection::IRElection(const std::string& filename) : Election("IR", filename) {
  audit_log.log("Starting Independent Runoff Election");

  // Log the file we are reading ballots from
  audit_log.log("Reading election information from: \'" + ballot_filename +
                "\'");

  audit_log.log("Parsing File Header");
  std::string line, name;
  for (int i = 0; i < 4; i++) {
    getline(ballot_file, line);
    if (i < 2) {
      continue;
    } else if (i == 2) {
      // parse candidates
      line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
      line.erase(std::remove(line.begin(), line.end(), '('), line.end());
      line.erase(std::remove(line.begin(), line.end(), ')'), line.end());
      std::istringstream ss(line);
      while (getline(ss, name, ',')) {
        // TODO(future): switch this to allow more than 1 character for the
        // party
        candidates.push_back(IRCandidate(name.substr(0, name.length() - 1),
                                         name.substr(name.length() - 1)));
      }
    } else if (i == 3) {
      total_ballots = std::stoull(line);
    }
  }
  audit_log.log("Finished Parsing Election Header");

  // Log parsed header data
  audit_log.log("Election Type: " + type);
  audit_log.log("Total Ballots: " + std::to_string(total_ballots));
  //
  // Log parsed candidates
  audit_log.log("Parsed " + std::to_string(candidates.size()) +
                " Candididates:");
  for (auto& can : candidates) {
    audit_log.log(can);
  }
}

void IRElection::parse_ballots() {
  audit_log.log("Parsing Ballots");

  // File is already open from Election constructor
  std::string line;
  while (getline(ballot_file, line)) {
    // store ballots in candidates
    IRBallot temp(line);
    int c_idx = temp.get_choice();
    if (c_idx != Ballot::NO_CHOICE) {
      // Put ballot into candidate, check to see if valid
      if(Validator::validate(temp.get_choices().size(),candidates.size())) {
        audit_log.log(temp);
        candidates.at(c_idx).add_ballot(temp);
      }
    } else {
      // Discard ballot without choice
      audit_log.log("Ballot with no choice discarded:");
      audit_log.log(temp);
    }
  }
  // Can close here otherwise it will also be called in destructor
  ballot_file.close();

  audit_log.log("Done Parsing Ballots");
}

void IRElection::redistribute(uint8_t candidate_index) {
  audit_log.log("Redistributing candidate at index " +
                std::to_string(candidate_index) + ":");
  audit_log.log(candidates[candidate_index]);

  // Mark candidate as eliminated
  candidates.at(candidate_index).eliminate();
  // Get the candidate ballots to redistribute
  std::queue<IRBallot> ballots = candidates.at(candidate_index).get_ballots();

  // Redistribute all the ballots
  while (!ballots.empty()) {
    // Pop the front ballot off the candidate queue
    IRBallot temp = ballots.front();
    ballots.pop();
    // Increment the ballot choice
    while (temp.get_choice() != Ballot::NO_CHOICE &&
           candidates.at(temp.get_choice()).get_eliminated()) {
      temp.increment_choice();
    }
    // Move ballot if choices remain
    // std::cout << candidates.at(temp.get_choice()).get_eliminated() <<
    // std::endl;
    if (temp.get_choice() != Ballot::NO_CHOICE) {
      // Print to audit log
      audit_log.log("Moving ballot from " + std::to_string(candidate_index) +
                    " to " + std::to_string(temp.get_choice()) + ":");
      audit_log.log(temp);
      // Actually move ballot
      candidates.at(temp.get_choice()).add_ballot(temp);
    } else {
      // Log ballot discard
      audit_log.log("Ballot Eliminated:");
      audit_log.log(temp);
    }
  }

  candidates.at(candidate_index).clear_ballots();

  audit_log.log("Finished redistributing candidate at index " +
                std::to_string(candidate_index) + ":");
  audit_log.log(candidates[candidate_index]);
}

void IRElection::announce_results() {
  std::stringstream output;
  // add information to media report
  output << "The winner of the election is "
         << candidates.at(winnerIndex).get_name() << " of party "
         << candidates.at(winnerIndex).get_party() << " with "
         << (float)candidates.at(winnerIndex).get_tally() * 100 / total_ballots
         << "% of the votes" << std::endl;
  for (int i = 0; i < candidates.size(); i++) {
    if (i == winnerIndex) {
      // do nothing
    } else if (!candidates.at(i).get_eliminated()) {
      output << candidates.at(i).get_name() << " had a peak of "
             << (float)candidates.at(i).get_tally() * 100 / total_ballots
             << "% of the votes." << std::endl;
    }
  }
  output << "Any remaining candidates were eliminated." << std::endl;
  // Print results to screen
  std::cout << output.str();
  // Write results to media report
  media_report.write(output.str());
  // Write results to audit log
  audit_log.log("ELECTION RESULTS:");
  audit_log.log(output.str());
  audit_log.log("END ELECTION RESULTS");
}

int IRElection::run() {
  // driver function for IR Elections
  std::vector<int> votes(candidates.size());
  bool found_winner = false;
  int majority = total_ballots / 2 + 1;

  // parse ballots
  parse_ballots();

  // while no winner loop until determined
  while (!found_winner) {
    // Get a list of the tallies to search for min and max
    votes.clear();
    for (int i = 0; i < candidates.size(); i++) {
      votes.push_back(candidates.at(i).get_tally());
    }

    // Find min, max votes
    int most_votes = -1;
    int least_votes = INT32_MAX;
    int max_location = -1;
    int min_location = -1;
    for (int i = 0; i < candidates.size(); i++) {
      if (!candidates.at(i).get_eliminated() &&
          candidates.at(i).get_tally() > most_votes) {
        most_votes = candidates.at(i).get_tally();
        max_location = i;
      }
    }
    for (int i = 0; i < candidates.size(); i++) {
      if (!candidates.at(i).get_eliminated() &&
          candidates.at(i).get_tally() < least_votes) {
        least_votes = candidates.at(i).get_tally();
        min_location = i;
      }
    }
    find_max_values(most_votes);

    // Check for majority
    if (most_votes >= majority) {
      audit_log.log("Majority Found");
      found_winner = true;
      if (max_indicies.size() == 1) {
        // Set the winner's index
        winnerIndex = max_location;
        // Write to the audit log
        audit_log.log("Majority Candidate Found:");
        audit_log.log(candidates[winnerIndex]);
      } else {
        // TODO(future): does this case ever get called
        audit_log.log("Multiple Majority Candidates Found, resolving tie");

        // Tie breaker
        std::size_t winner = TieBreaker::resolve_tie(max_indicies.size());
        // Write to the audit log
        audit_log.log("Tiebreaker winner:");
        audit_log.log(candidates[max_indicies.at(winner)]);
        // Set the winner index
        winnerIndex = max_indicies.at(winner);
      }
    } else {
      audit_log.log("No majority found. Redistributing votes");
      // if no majority and one candidate remains then they are winner
      int notEliminated = 0;
      int index = 0;
      for (int i = 0; i < candidates.size(); i++) {
        if (!candidates.at(i).get_eliminated()) {
          notEliminated++;
          index = i;
        }
      }

      if (notEliminated == 1) {
        found_winner = true;
        winnerIndex = index;
        break;
      }

      // Find the bottom candidates
      find_min_values(least_votes);

      // case where single loser
      if (min_indicies.size() == 1) {
        // Redistribute the single lowest candidate
        audit_log.log("Single lowest candidate:");
        redistribute(min_location);
      } else {
        audit_log.log("Multiple lowest candidates, breaking tie");
        // Break tie between multiple lowest candidates
        std::size_t loser = TieBreaker::resolve_tie(min_indicies.size());

        // Log who lost tiebreaker
        audit_log.log("Lost Tiebreaker:");
        audit_log.log(candidates[min_indicies.at(loser)]);

        // Tie breaker and redistribute
        redistribute(min_indicies.at(loser));
      }
    }
  }
  // Announce the results
  announce_results();

  // Return success
  return 0;
}

std::string IRElection::log() const {
  std::stringstream output;

  output << "IRElection: total_ballots=" << std::to_string(total_ballots);

  // Print the candidate names
  output << " candidates=[";

  auto candidate = candidates.begin();
  if (!candidates.empty()) {
    output << candidate->get_name();
    ++candidate;
  }
  for (; candidate != candidates.end(); ++candidate) {
    output << ", " << candidate->get_name();
    ++candidate;
  }
  output << "]";

  // TODO(someone): further logging?

  return output.str();
}

void IRElection::find_max_values(uint64_t max) {
  max_indicies.clear();
  // If the candidate has not been eliminated and they have the max, add them to
  // the list
  for (std::size_t i = 0; i < candidates.size(); ++i) {
    if (!candidates[i].get_eliminated() && candidates[i].get_tally() == max) {
      max_indicies.push_back(i);
    }
  }
}

void IRElection::find_min_values(uint64_t min) {
  min_indicies.clear();
  // If the candidate has not been eliminated and the have the min tally, add
  // them to the list
  for (std::size_t i = 0; i < candidates.size(); ++i) {
    if (!candidates[i].get_eliminated() && candidates[i].get_tally() == min) {
      min_indicies.push_back(i);
    }
  }
}
