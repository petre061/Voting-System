#!/usr/bin/env python3
from random import randrange, shuffle

FILENAME = "ir_random.csv"

NUM_CANDIDATES = 25
NUM_BALLOTS = 100000


def make_ir_ballot():

  num_choices = randrange(0, NUM_CANDIDATES + 1)

  # Shuffle into preferences
  choices = list(range(1, num_choices + 1))

  choices += [""] * (NUM_CANDIDATES - num_choices)

  shuffle(choices)

  # print(choices)
  # print(len(choices))
  # choices.sort()
  # print(choices)

  return ",".join(map(str, choices)) + "\n"


print("Writing")

with open(FILENAME, "w") as file:
  # Write the header
  file.write("IR\n")
  file.write(str(NUM_CANDIDATES) + "\n")

  # Write the candidates
  for i in range(1, NUM_CANDIDATES):
    file.write("Candidate{n} (Test{n}), ".format(n=i))
  file.write("Candidate{n} (Test{n})\n".format(n=NUM_CANDIDATES))

  # Write the number of ballots
  file.write(str(NUM_BALLOTS) + "\n")

  # Write the ballots
  for i in range(0, NUM_BALLOTS):
    file.write(make_ir_ballot())

print("Done")

