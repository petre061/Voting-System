// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#include "test_Validator.h"

TEST_F(fixture_VALIDATOR, validballot) {
    ballot = IRBallot(1,2,3,4);
    valid = Validator::validate(ballot->get_choices.size(),4);
    ASSERT_LT(valid, 1);
}

TEST_F(fixture_VALIDATOR, validballot_morethanhalf) {
    ballot = IRBallot(1,2,3,,);
    valid = Validator::validate(ballot->get_choices.size(),4);
    ASSERT_LT(valid, 1);
}

TEST_F(fixture_VALIDATOR, invalidballot) {
    ballot = IRBallot(,,,,);
    valid = Validator::validate(ballot->get_choices.size(),4);
    ASSERT_LT(valid, 0);
}