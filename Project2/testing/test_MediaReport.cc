/**
 * @file test_MediaReport.cc
 * @author Alex Bohm (bohm0080@umn.edu)
 * @brief Test the MediaReport class
 * @version 1.0
 * @date 2021-03-24
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "test_MediaReport.h"

#include <string>
/**
 * @brief Test that making a media report creates a file
 *
 */
TEST_F(fixture_MediaReport, FileCreation) {
  MediaReport report("test_media_report.txt");

  // Test MediaReport with one ballot and one vote

  // election results
  report.write("Winner of the election is: Mobambe Harambe");
  report.write("Party of the winner: I");
  report.write("Number of votes for winner: 1");

  // Check that the file was created

  std::ifstream audit_file("test_media_report.txt");

  ASSERT_TRUE(audit_file.is_open()) << "Unable to open media report";
}
/**
 * @brief Test that media reports contain strings we write to them
 *
 */
TEST_F(fixture_MediaReport, write) {
  const std::string results = "Winner of the election is: Mobambe Harambe";

  MediaReport report("test_media_report.txt");

  // Test MediaReport with one ballot and one vote

  // election results
  report.write(results);
  report.write("Party of the winner: I");
  report.write("Number of votes for winner: 1");

  std::ifstream media_file("test_media_report.txt");

  ASSERT_TRUE(media_file.is_open()) << "Unable to open media report";

  std::string file_contents;

  // Resize the string to the size of the file
  media_file.seekg(0, std::ios::end);
  file_contents.reserve(media_file.tellg());
  media_file.seekg(0, std::ios::beg);

  // Fill string with the file's contents
  file_contents.assign(std::istreambuf_iterator<char>(media_file),
                       std::istreambuf_iterator<char>());

  ASSERT_NE(file_contents.find(results), std::string::npos);
}
