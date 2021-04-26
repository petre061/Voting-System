// Copyright 2021, CSCI 5801 Spring 2021 Team 20
#include "test_OPLElection.h"
#include <unistd.h>
#include "OPLBallot.h"
#include "OPLCandidate.h"
#include "OPLParty.h"
unsigned int microsecond = 1000000;
TEST_F(fixture_OPLElection, OPLElectionFunctionality) {
  // Test basic functionality
  election = new OPLElection("./ballot_files/opl_random.csv");
  ASSERT_EQ(election->run(),0);
}
// TEST_F(fixture_OPLElection, OPLElectionMorePartiesThanSeats) {
//   election = new OPLElection("./ballot_files/opl_example.csv");
//   ASSERT_EQ(election->run(),0);
// }

TEST_F(fixture_OPLElection, OPLElection3waytie) {
  // Test whether each of the 3 parties wins the tie an approximately equal number of times
  election = new OPLElection("./ballot_files/opl_partyTie.csv");
  int dwins = 0;
  int rwins = 0;
  int iwins = 0;
   for(int i = 0; i < 10; i++) {
    std::cout << "in for loop, iteration #" << i << "\n";
    // Redirect cout stream to a buffer, collecting output which lists who won how many seats
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::ostringstream strCout;
    std::cout.rdbuf(strCout.rdbuf());
    election->run();
    // Re-redirect cout stream back to normal
    std::cout.rdbuf(oldCoutStreamBuf);
    std::cout << "post election run";
    // Read out printout line by line
    std::istringstream f(strCout.str());
    std::string line;
    while(std::getline(f,line)) {
      std::cout << line << "\n";
      if(line.compare("Party D won 1 seats.") == 0) {
         dwins++;
       }
      if(line.compare("Party R won 1 seats.") == 0) {
         rwins++;
       }
      if(line.compare("Party I won 1 seats.") == 0) {
        iwins++;
      }
    }
   }
  std::cout << "D won " << dwins << " times\n";
  std::cout << "R won " << rwins << " times\n";
  std::cout << "I won " << iwins << " times\n";
  float prop = round(100*(float(dwins) / float(1000000)));
  ASSERT_EQ(prop, 33);
}