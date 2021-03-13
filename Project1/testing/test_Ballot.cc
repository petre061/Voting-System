#include "test_Ballot.h"

#include <set>

#include "gtest/gtest.h"

TEST_F(fixture_Ballot, BallotUniqueID) {
  // Test unique id generation
  TestBallot* ballot1 = new TestBallot();
  TestBallot* ballot2 = new TestBallot();
  ASSERT_EQ(ballot2->get_id(), ballot1->get_id() + 1);
  delete ballot1;
  delete ballot2;
}

TEST_F(fixture_Ballot, BallotUniqueIDRepeat) {
  ballot = nullptr;
  // Set up a database for previously generated ids
  std::set<uint64_t> ids;

  // Generate a bunch of ballots and test that every id is unique
  for (uint64_t i = 0; i < 100000; ++i) {
    ballot = new TestBallot();
    // Make sure ballot's id was not already created
    ASSERT_EQ(ids.find(ballot->get_id()), ids.end())
        << "Non-Unique ID Found. get_id()=" << ballot->get_id();
    // Insert ballot id into set
    ids.insert(ballot->get_id());
    delete ballot;
  }
  ballot = nullptr;
}
