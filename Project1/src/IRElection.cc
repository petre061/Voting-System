
// Copyright CSCI 5801 Spring 2021 Team 20

#include "IRElection.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>

#include "Ballot.h"

IRElection::IRElection(const std::string& filename) : Election("IR", filename) {
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
        // TODO: switch this to allow more than 1 character for the party
        candidates.push_back(IRCandidate(name.substr(0, name.length() - 1),
                                         name.substr(name.length() - 1)));
      }
    } else if (i == 3) {
      total_ballots = std::stoi(line);
    }
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
      // Put ballot into candidate
      audit_log.log(temp);
      candidates.at(c_idx).add_ballot(temp);
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

  // redistribute among candidates
  std::queue<IRBallot> ballots;
  candidates.at(candidate_index).eliminate();
  ballots = candidates.at(candidate_index).get_ballots();
  while (!ballots.empty()) {
    IRBallot temp = ballots.front();
    temp.increment_choice();
    if (temp.get_choice() != Ballot::NO_CHOICE) {
      candidates.at(temp.get_choice()).add_ballot(temp);
    }
    ballots.pop();
  }

  audit_log.log("Finished redistributing candidate at index " +
                std::to_string(candidate_index) + ":");
  audit_log.log(candidates[candidate_index]);
}

void IRElection::announce_results() {
  // add information to media report
  std::cout << "The winner of the election is "
            << candidates.at(winnerIndex).get_name() << " of party "
            << candidates.at(winnerIndex).get_party() << " with "
            << candidates.at(winnerIndex).get_tally() * 100 / total_ballots
            << "% of the votes" << std::endl;
  for (int i = 0; i < candidates.size(); i++) {
    if (i == winnerIndex) {
      // do nothing
    } else {
      std::cout << candidates.at(i).get_name() << " had "
                << candidates.at(i).get_tally() * 100 / total_ballots
                << "% of the votes." << std::endl;
    }
  }
}

int IRElection::run() {
  // driver function for IR Elections
  std::vector<int> votes(candidates.size());
  bool found_winner = false;
  int majority = (total_ballots + 1) / 2;

  // parse ballots
  parse_ballots();

  // while no winner loop until determined
  while (!found_winner) {
    for (int i = 0; i < candidates.size(); i++) {
      if (!candidates.at(i).get_eliminated()) {
        votes.at(i) = candidates.at(i).get_tally();
      }
    }

    // check for majority
    auto most_votes = std::max_element(std::begin(votes), std::end(votes));
    auto least_votes = std::min_element(std::begin(votes), std::end(votes));
    int max_location = std::distance(std::begin(votes), most_votes);
    int least_location = std::distance(std::begin(votes), least_votes);
    find_max_values(votes, *most_votes);

    if (*most_votes >= majority) {
      found_winner = true;
      if (max_indicies.size() == 1) {
        winnerIndex = max_location;
      } else {
        // Tie breaker
        winnerIndex =
            max_indicies.at(TieBreaker::resolve_tie(max_indicies.size()));
      }
    } else {
      find_min_values(votes, *least_votes);

      // case where single loser
      if (min_indicies.size() == 1) {
        redistribute(least_location);
      } else {
        // Tie breaker and redistribute
        redistribute(
            min_indicies.at(TieBreaker::resolve_tie(min_indicies.size())));
      }
    }
    max_indicies.clear();
    min_indicies.clear();
    votes.clear();
  }

  announce_results();

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

void IRElection::find_max_values(std::vector<int> tallies, int max) {
  for (int i = 0; i < tallies.size(); i++) {
    if (tallies.at(i) && tallies.at(i) == max) {
      max_indicies.push_back(i);
    }
  }
}

void IRElection::find_min_values(std::vector<int> tallies, int min) {
  for (int i = 0; i < tallies.size(); i++) {
    if (tallies.at(i) && tallies.at(i) == min) {
      min_indicies.push_back(i);
    }
  }
}
