// Copyright 2021, CSCI 5801 Spring 2021 Team 20
#include "MediaReport.h"

MediaReport::MediaReport(const std::string& report_name)
    : filename(report_name), file(filename) {
  // File is already (probably) open from initializer list

  // If unable to open file specified, throw exception
  if (!file.is_open()) {
    throw std::invalid_argument("Unable to create MediaReport \'" + filename +
                                "\'");
  }

  // Write media report header
  file << "Voting System 1.0" << std::endl;
  file << "Official Press Release" << std::endl;
  file << "Report Generated: " << get_time_date() << std::endl;
}
void MediaReport::write(const std::string& text) {
  // Write text to file
  file << text << std::endl;
}
std::string MediaReport::get_time_date() {
  // Return the current time as a string
  auto now =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  return std::ctime(&now);
}
