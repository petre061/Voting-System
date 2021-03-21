// Copyright 2021, CSCI 5801 Spring 2021 Team 20
/**
 * @file OPLElection.cc
 * @author Peter Linden (linde764@umn.edu)
 * @author Nikhil Srikanth (srika018@umn.edu)
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief This file implementes the OPL Party class.
 * @version 1.0
 * @date 2021-03-14
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "OPLParty.h"
#include "TieBreaker.h"
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <queue>

OPLParty::OPLParty(const std::string& name) {
  pname = name;
}

uint64_t OPLParty::get_tally() {
  uint64_t tally =0;
  // Iterate through the length of the list of candidates attributed to the OPLParty instance, and add their tally() returns to a total party tally
  for (int i = 0; i < candidates.size(); i++) {
    tally += candidates.at(i)->get_tally();
  }
  return tally;
}

void OPLParty::add_candidate(OPLCandidate* new_candidate) {
  // Add a new candidate to the OPLParty's list of attributed candidates
  candidates.push_back(new_candidate);
  return;
}

std::string OPLParty::log() const {
  std::stringstream output;
  output << "OPL Party " << pname << ": [";
  for(int i = 0; i < candidates.size(); i++) {
    // For all OPLCandidate objects attributed to specific OPLParty:
    output << candidates.at(i)->log() << ",";
    // Display the ballot ID and choice for each OPLBallot for each candidate in the party   
  }
  output << "]";
  return output.str();
}

std::string OPLParty::get_name(){
  return pname;
}

std::vector<std::string> OPLParty::get_top_n_candidate_names(int n) {
  // // custom comparator for OPL candidate max heap
  // auto comp = [](OPLCandidate* one, OPLCandidate* two) {
  //   return one->get_tally() < two->get_tally();
  // };

  // // get top n candidates
  // std::priority_queue<OPLCandidate*, std::vector<OPLCandidate*>, decltype(comp)> candidate_max_heap(comp);
  //std::vector<std::string> result;
  // OPLCandidate* top1;
  // OPLCandidate* top2;

  // // push candidates into heap
  // for(int i = 0; i < candidates.size(); i++) {
  //   candidate_max_heap.push(candidates.at(i));
  // }
  // while(n > 0) {

  //   // get top 2 candidates if possible and break tie if necessary
  //   top1 = candidate_max_heap.top();
  //   candidate_max_heap.pop();
  //   if(!candidate_max_heap.empty()) {
  //     top2 = candidate_max_heap.top();
  //     if(top1->get_tally() == top2->get_tally()) {
  //       if(TieBreaker::flip()) {
  //         result.push_back(top1->get_name());
  //       }
  //       else {
  //         result.push_back(top2->get_name());
  //         candidate_max_heap.pop();
  //         candidate_max_heap.push(top1);
  //       }
  //     }
  //     else {
  //       result.push_back(top1->get_name());
  //     }
  //   }

  //   // otherwise just add the top candidate name
  //   else {
  //     result.push_back(top1->get_name());
  //   }

  //   // decrement seats available
  //   n--;
  // }

  // std::cout << result.size() << std::endl;
  //return result; 
  std::vector<OPLCandidate*> candidate_list = get_candidates();
  std::vector<std::string> result;
  int seats = n;
  if(seats > candidate_list.size()) {
    throw std::invalid_argument("Request of candidates is larger than number of candidates associated with party");
  }
  while(candidate_list.size() > 0) {
    if(seats > 0) {
      int tally = 0;
      int index = 255;
      for(int i = 0; i < candidate_list.size(); i++) {
        if(candidate_list.at(i)->get_tally() >= tally) {
          tally = candidate_list.at(i)->get_tally();
          index = i;
        }
      }
      //std::cout << "next most popular candidate is " << candidate_list.at(index)->get_name() << " with " << candidate_list.at(index)->get_tally();
      //if(index != 255) {
      result.push_back(candidate_list.at(index)->get_name());
      std::vector<OPLCandidate*>::iterator i = candidate_list.begin() + index;
      candidate_list.erase(i);
      seats --;
      //}
      // else {
      //   seats = 0;
      // }
    }
    else {
      break;
    }
  }
  // std::stringstream output;
  // for(int i = 0; i < result.size(); i++) {
  //   output << result.at(i);
  // }
  // //std::cout << "result is " << output.str();
  // return output.str();

  return result;
}

std::vector<OPLCandidate*> OPLParty::get_candidates() {
  return candidates;
}
// Creating / adding to candidates DS done in OPLElection class?