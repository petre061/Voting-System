
#include <iostream>

#include "../src/IRBallot.h"

int main(int argc, char const *argv[]) {
  std::string line = argv[1];

  IRBallot test(line);

  std::cout << test.log() << std::endl;

  return 0;
}
