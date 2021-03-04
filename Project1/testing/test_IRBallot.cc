
#include "test_IRBallot.h"

TEST_F(fixture_IRBallot, IRBallotCSVParse) {
  // Test basic functionality
  ballot = new IRBallot("1,2,3,4");
  ASSERT_EQ(ballot->get_choices().size(), 4);
  delete ballot;

  // Test no choices
  ballot = new IRBallot(",,,,");
  ASSERT_EQ(ballot->get_choices().size(), 0);
  delete ballot;

  // Test empty string
  ballot = new IRBallot("");
  ASSERT_EQ(ballot->get_choices().size(), 4);
  delete ballot;
}