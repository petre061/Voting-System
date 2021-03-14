
#include "test_AuditLog.h"
#include <string>

TEST_F(fixture_AuditLog, FileCreation) {
  
  // Test AuditLog with IR Voting with one ballot and one vote
  
  // ballot information
  log = new AuditLog("test_audit_log.txt");
  log->log("Number of canidates: 5");
  log->log("Name of candidates: /n Ronald McDonald (R) /n  Barack Mobamba (D) /n Donald Trump (G) /n Jeff Epstien /n Mobambe Harambe (I)");
  log->log("Number of ballots: 1");
  log->log("Ballots: ,,,,1");

  // ballot processing
  log->log("Number of ballots being processed: 1");
  log->log("Ballot 1 voted for: 1 - Mobambe Harambe (I)");
  log->log("Processing Complete /n Mobambe Harambe of the I party has won with a majority ");

  // election results 
  log->log("Winner of the election is: Mobambe Harambe");
  log->log("Party of the winner: I");
  log->log("Number of votes for winner: 1");

  delete log;
  log = nullptr;
}
