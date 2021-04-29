// Copyright CSCI 5801 Spring 2021 Team 20
/**
 * @file POElection.cc
 * @author Andrew Petrescu (petre061@umn.edu)
 * @brief This file implements the PO Election class.
 * @version 1.0
 * @date 2021-04-25
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "POElection.h"
#include "POCandidate.h"
#include "POParty.h"

#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <iostream>

POElection::POElection(std::string filename) : Election("PO", filename) {
    audit_log.log("Starting PO Election");

    audit_log.log("Parsing file header");
    std::string line, name, party;
    std::map<std::string, int> p_idx; // used to map the parties to their indexes in the vector
    int p_idx_count = 0; // map index counter
    for (int i = 0; i < 5; i++) {
        getline(ballot_file, line);
        if (i < 2) {
            continue;
        }
        else if (i == 2) {
            // parse candidates/parties
            // format line
            line.erase(std::remove(line.begin(), line.end(), '['), line.end());
            line.erase(std::remove(line.begin(), line.end(), ']'), line.end());
            line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

            // parse information and create/assign objects
            std::istringstream ss(line);
            while (getline(ss, name, ',')) {
                if (!name.empty()) {
                    // if(name.compare("eol") != 0) {
                    POCandidate* temp = new POCandidate(name);
                    candidates.push_back(temp);
                    getline(ss, party, ',');
                    //std::cout << party << "\n";
                    // adding first party and candidate
                    if (parties.size() == 0) {
                        parties.push_back(POParty(party));
                        parties.back().add_candidate(temp);
                        p_idx[party] = p_idx_count++;
                        // if the party exists add candidate there
                    }
                    else if (p_idx.find(party) != p_idx.end()) {
                        //std::cout << party << "\n";
                        parties.at(p_idx.find(party)->second).add_candidate(temp);

                        // party does not exist yet so add
                    }
                    else if (p_idx.find(party) == p_idx.end()) {
                        parties.push_back(POParty(party));
                        parties.back().add_candidate(temp);
                        p_idx[party] = p_idx_count++;
                    }
                }
            }
        }
        else if (i == 4) {
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

void POElection::parse_ballots() {
    audit_log.log("Parsing ballots");

    // File is already open from constructor of Election
    int candidate_idx = 0;
    std::string line, index;
    while (getline(ballot_file, line)) {
        POBallot temp(line);
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

void POElection::announce_results() {
    audit_log.log("ELECTION RESULTS: ");
    for (int i = 0; i < parties.size(); i++) {
        std::stringstream output;
        std::vector<std::string> temp_candidates = party_candidates[parties.at(i).get_name()];
        int percent_of_total = parties.at(i).get_tally() * 100 / total_ballots;
        output << "Party " << parties.at(i).get_name() << " won " << std::endl;
        output << "They won " << percent_of_total << "% of the total votes and " << std::endl;
        
        output << std::endl << std::endl;
        audit_log.log(output.str());
        std::cout << output.str();
        media_report.write(output.str());
    }

    audit_log.log("END ELECTION RESULTS");
}

int POElection::run() {
    std::cout << "START RUN" << std::endl;
    // parse ballots
    parse_ballots();
    std::cout << "ANNOUNCE RESULT" << std::endl;
    // display results
    announce_results();
    return 0;
}
// PLACEHOLDER FOR LOG UNTIL USAGE IS DECIDED TONIGHT
std::string POElection::log() const {
    return "";
    // // TODO: log PO election movements/information
    //   std::stringstream output;

    //   output << "POElection: total_ballots=" << std::to_string(total_ballots);

    //   // Print the candidate names
    //    output << " candidates=[";

    // auto candidate = *candidates.begin();
    // if (!candidates.empty()) {
    //   output << candidate->get_name();
    //   ++candidate;
    // }
    // for (; candidate != *candidates.end(); ++candidate) {
    //   output << ", " << candidate->get_name();
    //   //++candidate;
    // }
    // output << "]";

    //   return output.str();
}

void POElection::find_max_values(std::vector<int> tallies, int max) {
    for (int i = 0; i < tallies.size(); i++) {
        if (tallies.at(i) && tallies.at(i) == max)
            max_indicies.push_back(i);
    }
}