#===============================================================================
# Programming Assignment 1, part C
# Name: Chris Dang
# x500 Login: dangx225
# ID number: 5323765
# Course: CSCI 4041-011
# Professor: Nikolaos Papanikolopoulos
#===============================================================================

#strings for testing
#inString = "abaabababbabababbababaa"
#subStr = "ababbababaa"



# Function developed from next algorithm from notes
def computeNext(inString):

  newInString = [0] + list(inString) # buffer with  0 for ease implementation

  m = len(newInString)

  nextT = []

  for i in range(0, m): # zero out next table
    nextT.append(0)
  
  nextT[1] = -1 # initialize according to lecture
  nextT[2] = 0

  for i in range (3, m):
    j = nextT[i-1]+1

    while newInString[i-1] != newInString[j] and j > 0:
      j = nextT[j]+1
      
    nextT[i] = j

  return nextT[1:len(nextT)] #splice to get proper next table



# Function developed from string match algorithm from notes
def stringMatch(inString, subStr):

  newInString = [0] + list(inString)  
  newSubStr = [0] + list(subStr)
  
  n = len(inString)
  m = len(subStr)

  
  nextArr = [0] + computeNext(subStr) # buffer with  0 for ease implementation

  j = 1
  i = 1
  start = 0

  while start == 0 and i <= n:
    if newSubStr[j] == newInString[i]: # strings match?
      j = j + 1 # Yes: increment pointers
      i = i + 1

    else:
      j = nextArr[j] + 1 # No: move along
      if i == 0:
        j = 1 
        i = i + 1

    if j == m + 1:
      start = i - m

  return start



stringFile = open("string_info.txt")
inString = stringFile.readline()      # first line contains the whole string
subStr = stringFile.readline()        # second line contains the substring to be matched in the whole string



# dislay
print "START = ", stringMatch(inString, subStr)


















    
    
