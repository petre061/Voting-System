
#include "test_AuditLog.h"

#include <fstream>
#include <string>

#include "IRBallot.h"
#include "IRCandidate.h"
#include "OPLBallot.h"
#include "OPLCandidate.h"
#include "OPLParty.h"

TEST_F(fixture_AuditLog, FileCreation) {
  // Test AuditLog with IR Voting with one ballot and one vote

  const std::string first_line = "LOG TEST BEGIN";
  const std::string last_line = "LOG TEST END";

  // ballot information
  AuditLog log("test_audit_log.txt");

  log.log(first_line);

  log.log("Number of canidates: 5");
  log.log(
      "Name of candidates: /n Ronald McDonald (R) /n  Barack Mobamba (D) /n "
      "Donald Trump (G) /n Jeff Epstien /n Mobambe Harambe (I)");
  log.log("Number of ballots: 1");
  log.log("Ballots: ,,,,1");

  // ballot processing
  log.log("Number of ballots being processed: 1");
  log.log("Ballot 1 voted for: 1 - Mobambe Harambe (I)");
  log.log(
      "Processing Complete /n Mobambe Harambe of the I party has won with a "
      "majority ");

  // election results
  log.log("Winner of the election is: Mobambe Harambe");
  log.log("Party of the winner: I");
  log.log("Number of votes for winner: 1");

  log.log(last_line);

  // Check audit log contains the first and last lines we wrote
  std::ifstream audit_file("test_audit_log.txt");

  ASSERT_TRUE(audit_file.is_open()) << "Unable to open test_audit_log.txt";

  bool found_first_line = false;
  bool found_last_line = false;

  std::string line = "";
  while (audit_file.good()) {
    if (!found_first_line && line.find(first_line) != std::string::npos) {
      found_first_line = true;
    } else if (!found_last_line && line.find(last_line) != std::string::npos) {
      found_last_line = true;
    }
    getline(audit_file, line);
  }
  ASSERT_TRUE(found_first_line) << "Unable to find first line logged";
  ASSERT_TRUE(found_last_line) << "Unable to find last line logged";
}
TEST_F(fixture_AuditLog, ObjectLoggingIRBallot) {
  AuditLog log("test_audit_log_ObjectLoggingIRBallot.txt");
  // Create a  to log
  IRBallot object("1,2,3,4");
  // Capture what we expect to see in the log
  const std::string text = object.log();
  // Write a  to the audit log
  log.log(object);

  // Check that the audit log contains the object

  std::ifstream audit_file("test_audit_log_ObjectLoggingIRBallot.txt");

  ASSERT_TRUE(audit_file.is_open());

  std::string file_contents;

  // Resize the string to the size of the file
  audit_file.seekg(0, std::ios::end);
  file_contents.reserve(audit_file.tellg());
  audit_file.seekg(0, std::ios::beg);

  // Fill string with the file's contents
  file_contents.assign(std::istreambuf_iterator<char>(audit_file),
                       std::istreambuf_iterator<char>());

  ASSERT_NE(file_contents.find(text), std::string::npos);
}
TEST_F(fixture_AuditLog, ObjectLoggingIRCandidate) {
  AuditLog log("test_audit_log_ObjectLoggingIRCandidate.txt");
  // Create a  to log
  IRCandidate object("Bob", "Builder");
  // Capture what we expect to see in the log
  const std::string text = object.log();
  // Write a  to the audit log
  log.log(object);

  // Check that the audit log contains the object

  std::ifstream audit_file("test_audit_log_ObjectLoggingIRCandidate.txt");
  ASSERT_TRUE(audit_file.is_open());

  std::string file_contents;
  // Resize the string to the size of the file
  audit_file.seekg(0, std::ios::end);
  file_contents.reserve(audit_file.tellg());
  audit_file.seekg(0, std::ios::beg);

  // Fill string with the file's contents
  file_contents.assign(std::istreambuf_iterator<char>(audit_file),
                       std::istreambuf_iterator<char>());

  ASSERT_NE(file_contents.find(text), std::string::npos);
}
TEST_F(fixture_AuditLog, ObjectLoggingOPLBallot) {
  AuditLog log("test_audit_log_ObjectLoggingOPLBallot.txt");
  // Create a  to log
  OPLBallot object(",,1,");
  // Capture what we expect to see in the log
  const std::string text = object.log();
  // Write a  to the audit log
  log.log(object);

  // Check that the audit log contains the object

  std::ifstream audit_file("test_audit_log_ObjectLoggingOPLBallot.txt");

  ASSERT_TRUE(audit_file.is_open());

  std::string file_contents;

  // Resize the string to the size of the file
  audit_file.seekg(0, std::ios::end);
  file_contents.reserve(audit_file.tellg());
  audit_file.seekg(0, std::ios::beg);

  // Fill string with the file's contents
  file_contents.assign(std::istreambuf_iterator<char>(audit_file),
                       std::istreambuf_iterator<char>());

  ASSERT_NE(file_contents.find(text), std::string::npos);
}
TEST_F(fixture_AuditLog, ObjectLoggingOPLCandidate) {
  AuditLog log("test_audit_log_ObjectLoggingOPLCandidate.txt");
  // Create a  to log
  OPLCandidate object("Bob");
  // Capture what we expect to see in the log
  const std::string text = object.log();
  // Write a  to the audit log
  log.log(object);

  // Check that the audit log contains the object

  std::ifstream audit_file("test_audit_log_ObjectLoggingOPLCandidate.txt");

  ASSERT_TRUE(audit_file.is_open());

  std::string file_contents;

  // Resize the string to the size of the file
  audit_file.seekg(0, std::ios::end);
  file_contents.reserve(audit_file.tellg());
  audit_file.seekg(0, std::ios::beg);

  // Fill string with the file's contents
  file_contents.assign(std::istreambuf_iterator<char>(audit_file),
                       std::istreambuf_iterator<char>());

  ASSERT_NE(file_contents.find(text), std::string::npos);
}
TEST_F(fixture_AuditLog, ObjectLoggingOPLParty) {
  AuditLog log("test_audit_log_ObjectLoggingOPLParty.txt");
  // Create a  to log
  OPLParty object("Builder");
  // Capture what we expect to see in the log
  const std::string text = object.log();
  // Write a  to the audit log
  log.log(object);

  // Check that the audit log contains the object

  std::ifstream audit_file("test_audit_log_ObjectLoggingOPLParty.txt");

  ASSERT_TRUE(audit_file.is_open());

  std::string file_contents;

  // Resize the string to the size of the file
  audit_file.seekg(0, std::ios::end);
  file_contents.reserve(audit_file.tellg());
  audit_file.seekg(0, std::ios::beg);

  // Fill string with the file's contents
  file_contents.assign(std::istreambuf_iterator<char>(audit_file),
                       std::istreambuf_iterator<char>());

  ASSERT_NE(file_contents.find(text), std::string::npos);
}
