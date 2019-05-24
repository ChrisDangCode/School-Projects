#===============================================================================
# Programming Assignment 2, part A
# Name: Chris Dang
# x500 Login: dangx225
# ID number: 5323765
# Course: CSCI 4041-011
# Professor: Nikolaos Papanikolopoulos
#===============================================================================
import Queue
import heapq



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

#===============================================================================
#for i in range(0, len(temp)):
#        for j in range(i, len(temp)):
#                print "temp[", i,"][", j, "] is" , temp[i][j]
#===============================================================================

def prim(graph, w, root):

    #for u in range(0, len(graph)):

    #q = Queue.PriorityQueue()

    q = []
    
    # from diagonol down, grab weights of edges
    for i in range(0, len(graph)):
        for j in range(i, len(graph)):
            if graph[i][j] != 0:
                t = (graph[i][j], i, j)
                q.append(t)

    
    #sort edges
    q.sort()

    print "q is:", q

    


    # Read me please!
    # Display of what prim is meant to do:
    # Prim from here will visit each vertice adjacent to the root.
    # This will continue recursivly until it reaching a previoulsy visited vertice.
    # Prim will then backtrack to the top call, and visit a new vertice,
    # continuing until all vertices are found.

    # This can be implemented by going through the adjancy matrix and running through
    # the matrix, visiting the i-th row after visiting a vertice.
    while not q:
        u = heapq.heappop(q)
        #for v in 







# note: graph file must contain weights in the undirected adj. matrix
graphFile = open("graph_file.txt", "r") # get file

temp = [] # Temp is the matrix that Prim will be run on.

# split takes the line and splits the elements into seperate strings
# adds the line to the matrix
for line in graphFile:
        temp.append(line.split())

# converts the matrix of strings to ints
int_matrix(temp)


prim(temp, len(temp), 10)





#notepad = { "key" : "first", "value" : "second"}
#print "Keys are: " , notepad.keys()
#print "Values are: " , notepad.values()








