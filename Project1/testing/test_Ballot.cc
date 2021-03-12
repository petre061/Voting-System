#include "test_Ballot.h"
#include "gtest/gtest.h"

TEST_F(fixture_Ballot, BallotUniqueID) {
  // Test unique id generation
  ballot1 = new Ballot();
  ballot2 = new Ballot();
  ASSERT_EQ(ballot2->get_id(), ballot1->get_id()+1);
  delete ballot1;
  delete ballot2;

}

TEST_F(fixture_IRBallot, BallotUniqueIDRepeat) {
  for (int i = 1; i < 255; i ++) {
      ballot0 = new Ballot();
      ballot1 = new Ballot();
      ASSERT_EQ(ballot2->get_id(), ballot1->get_id()+1);
      delete ballot0;
      delete ballot1;
  }