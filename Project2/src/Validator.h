/**
 * @file Validation.h
 * @author Peter Linden // linde764
 * @brief This file implements a class meant to verify that each ballot in an IRV election is valid
 * @version 0.1
 * @date 2021-04-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
 
#ifndef PROJECT1_SRC_VALIDATOR_H_
#define PROJECT1_SRC_VALIDATOR_H_

class Validator {
    public:
    static bool validate(uint8_t num_choices, uint8_t total_candidates);

};

#endif