#===============================================================================
# Programming Assignment 2, part B
# Name: Chris Dang
# x500 Login: dangx225
# ID number: 5323765
# Course: CSCI 4041-011
# Professor: Nikolaos Papanikolopoulos
#===============================================================================


# new_matrix
# creates a new n x n matrix initialized with 0
def new_matrix(n):
    
    w = []
    for i in range(0, n):
        temp = []
        for j in range(0, n):
            temp.append(0)

        w.append(temp)
        
    return w

# print_matrix
# prints the matrix w
def print_matrix(w):

    for i in w:
        print i

# int_matrix
# converts a matrix of strings to matrix of ints
def int_matrix(w):

    for i in range(0, len(w)):
        for j in range(0, len(w)):
            w[i][j] = int(w[i][j])
            
    return w

# floyd_w
# executes floyd-warshall algo on a matrix w; prints intermediate steps
def floyd_w(w):
    n = len(w)

    print "Initial" # print initial matrix
    print_matrix(w)
    
    for m in range(0, n):   # n^3 algo
        for i in range(0, n):
            for j in range(0, n): # algo from notes
                if w[i][m] + w[m][j] < w[i][j]:
                    w[i][j] = w[i][m] + w[m][j]

        print "m =" , m+1 #printing intermediate
        print_matrix(w)
                    

#note, infinity is represented as 10,000 from the file
graphFile = open("weightgraph.txt", "r") # get file


temp = [] # Temp is the matrix


# split takes the line and splits the elements into seperate strings
# adds the line to the matrix
for line in graphFile:
    temp.append(line.split()) 

# converts the matrix of strings to ints
int_matrix(temp)

# executes Floyd-Warshall on matrix
floyd_w(temp)



graphFile.close() # close file

