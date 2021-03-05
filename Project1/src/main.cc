// Copyright CSCI 5801 Spring 2021 Team 20
#include <iostream>

#include "IRBallot.h"

int main(int argc, char const *argv[]) {
  std::string line = "1,2,3,4";

  if (argc > 1) {
    line = argv[1];
  }

  IRBallot b(line);
  std::cout << "Hello World" << std::endl;
  std::cout << b.log() << std::endl;
  return 0;
}
