// Copyright CSCI 5801 Spring 2021 Team 20
/**
 * @file OPLElection.cc
 * @author Nikhil Srikanth (srika018@umn.edu)
 * @author Peter Linden (linde764@umn.edu)
 * @author Alex Bohm (bohm0080@umn.edu)
 * @author Andrew Petrescu (petre061@umn.edu)
 * @brief This file implementes the OPL Election class.
 * @version 1.0
 * @date 2021-03-14
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "OPLElection.h"
#include "OPLCandidate.h"
#include "OPLParty.h"

#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <iostream>

OPLElection::OPLElection(std::string filename) : Election("OPL", filename) {
  audit_log.log("Starting OPL Election");

  audit_log.log("Parsing file header");
  std::string line, name, party;
  std::map<std::string, int> p_idx; // used to map the parties to their indexes in the vector
  int p_idx_count = 0; // map index counter
  for (int i = 0; i < 5; i++){
    getline(ballot_file, line);
    if (i < 2) {
      continue;
    } else if (i == 2) {
      // parse candidates/parties
      // format line
      line.erase(std::remove(line.begin(), line.end(), '['), line.end());
      line.erase(std::remove(line.begin(), line.end(), ']'), line.end());
      line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

      // parse information and create/assign objects
      std::istringstream ss(line);
      while (getline(ss, name, ',')){
        OPLCandidate* temp = new OPLCandidate(name);
        candidates.push_back(temp);
        getline(ss, party, ',');

        // adding first party and candidate
        if (parties.size() == 0) {
          parties.push_back(OPLParty(party));
          parties.back().add_candidate(temp);
          p_idx[party] = p_idx_count++;

          // if the party exists add candidate there
        } else if (p_idx.find(party) != p_idx.end()){
          parties.at(p_idx.find(party)->second).add_candidate(temp);

          // party does not exist yet so add
        } else {
          parties.push_back(OPLParty(party));
          parties.back().add_candidate(temp);
          p_idx[party] = p_idx_count++;
        }
      }
    } else if (i == 3) {
      num_seats = std::stoi(line);
    } else if (i == 4) {
      total_ballots = std::stoi(line);
    }
  }
  audit_log.log("Finished parsing header");

  // Log parsed header data
  audit_log.log("Election Type: " + type);
  audit_log.log("Total Ballots: " + std::to_string(total_ballots));

  // Log parsed candidates
  audit_log.log("Parsed " + std::to_string(candidates.size()) +
                " Candididates:");
  for (auto& can : candidates) {
    audit_log.log(*can);
  }
}

void OPLElection::parse_ballots() {
  audit_log.log("Parsing ballots");

  // File is already open from constructor of Election
  int candidate_idx = 0;
  std::string line, index;
  while (getline(ballot_file, line)) {
    OPLBallot temp(line);
    candidate_idx = temp.get_choice();
    if (candidate_idx != Ballot::NO_CHOICE) {
      audit_log.log(temp);
      candidates.at(candidate_idx)->add_ballot(temp);
    }
    else {
      // Discard ballot without choice
      audit_log.log("Ballot with no choice discarded:");
      audit_log.log(temp);
    }
  }
  // We can close ballot file here since we are probably done with it.
  // otherwise it will be closed in the destructor of Election
  ballot_file.close();
  
  audit_log.log("Done Parsing Ballots");
}

void OPLElection::assign_seats() {
  // assign seats to party/candidate
  std::vector<int> remainders(parties.size());
  std::vector<int> party_votes(parties.size());
  int total_seats = num_seats;

  // determine quota
  int quota = (int)total_ballots / num_seats;
  audit_log.log("The quota for this election is: " + std::to_string(quota));

  // assign initial seats to parties
  for(int i = 0; i < parties.size(); i++){
    int seats = (int)parties.at(i).get_tally() / quota;

    // if party won more seats than candidates only give them seats equal to number of candidates
    if(seats > parties.at(i).get_candidates().size()) {
      total_seats = total_seats - parties.at(i).get_candidates().size();
      party_seats[parties.at(i).get_name()] = parties.at(i).get_candidates().size();
      audit_log.log(parties.at(i).get_name() + " won more seats than candidates so they are only given seats for the " + std::to_string(parties.at(i).get_candidates().size()) + " candidate(s) they have");
    }
    else {
      total_seats = total_seats - seats;
      party_seats[parties.at(i).get_name()] = seats;
      audit_log.log(parties.at(i).get_name() + " won " + std::to_string(seats));
    }
    remainders.at(i) = parties.at(i).get_tally() % quota;
    audit_log.log(parties.at(i).get_name() + " has a vote remainder of: " + std::to_string(remainders.at(i)));

    // get parties tallies
    party_votes.at(i) = parties.at(i).get_tally();
  }
  // rank parties by remaining votes and allocate seats in order of highest remaining votes
  while(total_seats > 0) {
    auto most_rem = std::max_element(std::begin(remainders), std::end(remainders));
    int index = std::distance(std::begin(remainders), most_rem);
    find_max_values(remainders, *most_rem);
    if(max_indicies.size() == 1) {
      audit_log.log("Single party has largest remiander");
      party_seats[parties.at(index).get_name()]++;
      total_seats--;
      remainders.at(index) = 0;
    }
    else {
      // Tie break 
      audit_log.log("Tie for largest remainder");
      int w_index = max_indicies.at(TieBreaker::resolve_tie(max_indicies.size()));
      audit_log.log(parties.at(w_index).get_name() + " won the tie breaker");
      party_seats[parties.at(w_index).get_name()]++;
      total_seats--;
      remainders.at(w_index) = 0;
    }
    max_indicies.clear();
  }

  // assign candidates to seats based on number of votes 
  for(int i = 0; i < parties.size(); i++) {
    party_candidates[parties.at(i).get_name()] = parties.at(i).get_top_n_candidate_names(party_seats[parties.at(i).get_name()]);
  }
}

void OPLElection::announce_results() {
  audit_log.log("ELECTION RESULTS: ");
  for(int i = 0; i < parties.size(); i++) {
    std::stringstream output;
    std::vector<std::string> temp_candidates = party_candidates[parties.at(i).get_name()];
    int percent_of_total = parties.at(i).get_tally() * 100 / total_ballots;
    int percent_of_seats = party_seats[parties.at(i).get_name()] * 100 / num_seats;
    output << "Party " << parties.at(i).get_name() << " won " << party_seats[parties.at(i).get_name()] << " seats." << std::endl;
    output << "They won " << percent_of_total << "% of the total votes and " << percent_of_seats << "% of the seats" << std::endl;
    if(temp_candidates.size() > 0) {
      output << "The candidates that won those seats are: ";
      for(int j = 0; j < temp_candidates.size(); j++) {
        output << temp_candidates.at(j) << " ";
      }
    }
    output << std::endl << std::endl;

    audit_log.log(output.str());
    std::cout << output.str();
    media_report.write(output.str());
    
  }
  
  audit_log.log("END ELECTION RESULTS");
}

int OPLElection::run() {

  // parse ballots
  parse_ballots();
  // assign seats to parties
  assign_seats();
  // display results
  announce_results();
  std::cout << "done with announcing";
  return 0;
}

std::string OPLElection::log() const {
  //std::cout << " made it to log";
  // TODO: log OPL election movements/information
    std::stringstream output;

    output << "OPLElection: total_ballots=" << std::to_string(total_ballots);

    // Print the candidate names
     output << " candidates=[";

  auto candidate = *candidates.begin();
  if (!candidates.empty()) {
    output << candidate->get_name();
    ++candidate;
  }
  for (; candidate != *candidates.end(); ++candidate) {
    output << ", " << candidate->get_name();
    ++candidate;
  }
  output << "]";


    // Print number of party seats
    output << " party_seats=[";

    auto pseats = party_seats.begin();
    if (!party_seats.empty()) {
        output << num_seats;
        ++pseats;
    }
    for (; pseats != party_seats.end(); ++pseats) {
        output << num_seats;
        ++pseats;
    }
    output << "]";

    return output.str();
}

void OPLElection::find_max_values(std::vector<int> tallies, int max) {
  for(int i = 0; i < tallies.size(); i++) {
    if(tallies.at(i) && tallies.at(i) == max)
      max_indicies.push_back(i);
  }
}