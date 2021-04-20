#!/usr/bin/env python3
from random import randrange, shuffle, choice
# from bs4 import BeautifulSoup
# import requests
FILENAME = "opl_random.csv"

NUM_SEATS = 30
NUM_CANDIDATES = 500
NUM_PARTIES = 9
NUM_BALLOTS = 100000

# def get_data(url, file_name):

#     page = requests.get(url)
#     # extract text - now we have all the text from the page
#     soup = BeautifulSoup(page.text, "html.parser")


#     # now find the table with data we want. In order to do 
#     #it, we have to check the id of the table.
#     tbody = soup.find_all(id="myTable")
#     # if we want to see the output in command line
#     print(tbody)

#     # now it's time to store the data from the website.
#     f = open(file_name, "w+") # it creates a file in which 
#                               # it will write the data
#     records = []

#     # if we take a look at the output of print(tbody) we can
#     # see that we have many <td> and <tr> tag elements. 
#     # First we go through all the elements in tbody to find
#     # ALL tr (table row) elements
#     for elem in tbody:
#         rows = elem.find_all("tr")

#         # now we want to loop over rows. We can check how 
#         # many rows are there and decide how many names we 
#         # wish to store. I want to have many names, so I 
#         # decided to loop over 300 rows.
#         for row in rows[1:301]:

#             # in each row we want to find table data with a 
#             # name. Because in our rows, we have a few td 
#             # elements, but only the first td element 
#             # contains the name I'm using find("td") method
#             column = row.find("td")
#             # to extract only text we can use .text method,
#             # but because the names in the table are written 
#             #in UPPER CASE I'm .capitalize() method.
#             column_text = column.text.capitalize()

#             # store all the names in records list
#             records.append(column_text)

#     # the last step is to write the names into the file,
#     # each name in the new line
#     for record in records:
#         f.write(record + "\n")

# # I'm calling the function 3 times to have 3 files: one for 
# # women's first names, one for men's first names, and one 
# # for surnames

# url = "https://namecensus.com/data/1000.html"
# file_name = "last_names.txt"
# get_data(url, file_name)

# url = "https://namecensus.com/male_names.htm"
# file_name = "male_first_names.txt"
# get_data(url, file_name)

# url = "https://namecensus.com/female_names.htm"
# file_name = "female_first_names.txt"
# get_data(url, file_name)

# def name_array(file):
#     # open file with names
#     with open(file) as fp:
#         new_list = []
#         # loop through each line in the txt file 
#         for line in fp:
#             # remove white spaces next to each name and add
#             # to the new_list array
#             new_list.append(line.strip())
#     return new_list

# # call the function three times to transform names from each
# # file into arrays 
# file = "male_first_names.txt"
# male_names = name_array(file)

# file = "female_first_names.txt"
# female_names = name_array(file)

# file = "last_names.txt"
# last_names = name_array(file)

# def random_name():
#     mf = randrange(0,1)
#     if mf == 0:
#         # randomly choose male name and surname
#         result = random.choice(male_names).join(random.choice(last_names))
#     else:
#         # randomly choose female name and surname 
#         result = random.choice(female_names).join(random.choice(last_names))
#     return result

def make_opl_ballot():

  choices = randrange(0, NUM_CANDIDATES - 1)

  # Shuffle into preferences
  #choices = list(range(1, num_choices + 1))
  ballot = (","*choices)+"1"+(","*(NUM_CANDIDATES - 1 - choices)) + "\n"
    # 1, choice = 0 "" + 1 + ","*(2-1)
    # ,1

  # print(choices)
  # print(len(choices))
  # choices.sort()
  # print(choices)

  return ballot

# 6
# [Pike,D], [Foster,D],[Deutsch,R], [Borg,R], [Jones,R],[Smith,I]
# 3
# 9
# 1,,,,,
# 1,,,,,
print("Writing")

with open(FILENAME, "w") as file:
  # Write the header
  file.write("OPL\n")
  file.write(str(NUM_CANDIDATES) + "\n")

  # Write the candidates
  for i in range(1, NUM_CANDIDATES):
    file.write("[candidate, " + choice("CLSDUGPAF") + "], ".format(n=i))
  file.write("[candidate, " + choice("CLSDUGPAF") + "]\n".format(n=NUM_CANDIDATES))
# Parties modeled off UK Parliament: *C*onservative, *L*abour, *S*cottish National Party, Liberal *D*emocrats, Democratic *U*nionist
  # Write the number of parties
  file.write(str(NUM_SEATS) + "\n")
  # Write the number of ballots
  file.write(str(NUM_BALLOTS) + "\n")

  # Write the ballots
  for i in range(0, NUM_BALLOTS):
    file.write(make_opl_ballot())

print("Done")

