
#include "test_MediaReport.h"

TEST_F(fixture_MediaReport, MediaReportFileCreation) {
  report = new MediaReport("test_media_report.txt");

  delete report;
  report = nullptr;
}
