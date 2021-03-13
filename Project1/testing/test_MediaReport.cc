
#include "test_MediaReport.h"

TEST_F(fixture_MediaReport, MediaReportFileCreation) {
  report = new MediaReport("test_media_report.txt");

  // TODO(someone): Write this test
  FAIL() << "Implement this test";

  delete report;
  report = nullptr;
}
