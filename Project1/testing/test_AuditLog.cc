
#include "test_AuditLog.h"

TEST_F(fixture_AuditLog, FileCreation) {
  log = new AuditLog("test_audit_log.txt");

  log->log("Hello world");

  delete log;
  log = nullptr;
}
