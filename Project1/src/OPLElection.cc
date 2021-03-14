
// Copyright CSCI 5801 Spring 2021 Team 20

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
}

void OPLElection::parse_ballots() {
  // TODO: finish parse ballots

  // File is already open from constructor of Election
  int candidate_idx = 0;
  std::string line, index;
  while (getline(ballot_file, line)) {
    OPLBallot temp(line);
    candidate_idx = temp.get_choice();
    if (candidate_idx != Ballot::NO_CHOICE) {
      candidates.at(candidate_idx)->add_ballot(temp);
    }
  }
  // We can close ballot file here since we are probably done with it.
  // otherwise it will be closed in the destructor of Election
  ballot_file.close();
  return;
}

void OPLElection::assign_seats() {
  // assign seats to party/candidate
  std::vector<int> remainders(parties.size());
  std::vector<int> party_votes(parties.size());
  int total_seats = num_seats;

  // determine quota
  int quota = (int)total_ballots / num_seats;

  // assign initial seats to parties
  for(int i = 0; i < parties.size(); i++){
    int seats = (int)parties.at(i).get_tally() / quota;

    // if party won more seats than candidates only give them seats equal to number of candidates
    if(seats > parties.at(i).get_candidates().size()) {
      total_seats = total_seats - parties.at(i).get_candidates().size();
      party_seats[parties.at(i).get_name()] = parties.at(i).get_candidates().size();
    }
    else {
      total_seats = total_seats - seats;
      party_seats[parties.at(i).get_name()] = seats;
    }
    remainders.at(i) = parties.at(i).get_tally() % quota;

    // get parties tallies
    party_votes.at(i) = parties.at(i).get_tally();
  }
  // rank parties by remaining votes and allocate seats in order of highest remaining votes
  while(total_seats > 0) {
    auto most_rem = std::max_element(std::begin(remainders), std::end(remainders));
    int index = std::distance(std::begin(remainders), most_rem);
    find_max_values(remainders, *most_rem);
    if(max_indicies.size() == 1) {
      party_seats[parties.at(index).get_name()]++;
      total_seats--;
      remainders.at(index) = 0;
    }
    else {
      // Tie break 
      int w_index = max_indicies.at(TieBreaker::resolve_tie(max_indicies.size()));
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
  // TODO: send information to media report
  for(int i = 0; i < parties.size(); i++) {
    std::vector<std::string> temp_candidates = party_candidates[parties.at(i).get_name()];
    int percent_of_total = parties.at(i).get_tally() * 100 / total_ballots;
    int percent_of_seats = party_seats[parties.at(i).get_name()] * 100 / num_seats;
    std::cout << "Party " << parties.at(i).get_name() << " won " << party_seats[parties.at(i).get_name()] << " seats." << std::endl;
    std::cout << "They won " << percent_of_total << "% of the total votes and " << percent_of_seats << "% of the seats" << std::endl;
    std::cout << "The candidates that won those seats are: ";
    for(int j = 0; j < temp_candidates.size(); j++) {
      std::cout << temp_candidates.at(i) << " ";
    }
    std::cout << std::endl << std::endl;
  }

  return;
}

int OPLElection::run() {

  // parse ballots
  parse_ballots();
  // assign seats to parties
  assign_seats();
  // display results
  announce_results();

  return 0;
}

std::string OPLElection::log() const {
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