// Copyright CSCI 5801 Spring 2021 Team 20

#ifndef ELECTION_H_
#define ELECTION_H_

#include "Loggable.h"

#include <fstream>
#include <string>

/**
 * @brief
 */
class Election : public Loggable {
    protected:
        std::string ballot_filename;
        uint16_t total_ballots;
        std::string type;
        //TODO: Audit Log
        //TODO: Media Report
    
    public:
        Election() = default;
        virtual ~Election(){}
        virtual int run() = 0;
};

#endif 