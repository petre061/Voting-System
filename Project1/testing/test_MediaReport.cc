
#include "test_MediaReport.h"

TEST_F(fixture_MediaReport, MediaReportFileCreation) {
  report = new MediaReport("test_media_report.txt");

  // Test MediaReport with one ballot and one vote

  // election results 
  report->write("Winner of the election is: Mobambe Harambe");
  report->write("Party of the winner: I");
  report->write("Number of votes for winner: 1");

  delete report;
  report = nullptr;
}
