// Copyright 2021, CSCI 5801 Spring 2021 Team 20

#include "test_Validator.h"
#include "test_IRBallot.h"
#include "IRBallot.h"

TEST_F(fixture_VALIDATOR, validballot) {
    IRBallot ballot("1,2,3,4");
    bool valid = Validator::validate(ballot.get_choices().size(),4);
    bool result = true;
    ASSERT_EQ(valid, result);
}

TEST_F(fixture_VALIDATOR, validballot_morethanhalf) {
    IRBallot ballot("1,2,3,,");
    bool valid = Validator::validate(ballot.get_choices().size(),4);
    bool result = true;
    ASSERT_EQ(valid, result);
}

TEST_F(fixture_VALIDATOR, invalidballot) {
    IRBallot ballot(",,,,");
    bool valid = Validator::validate(ballot.get_choices().size(),4);
    bool result = false;
    ASSERT_EQ(valid, result);
}