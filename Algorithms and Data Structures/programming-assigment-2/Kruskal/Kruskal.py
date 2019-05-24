#===============================================================================
# Programming Assignment 2, part A
# Name: Chris Dang
# x500 Login: dangx225
# ID number: 5323765
# Course: CSCI 4041-011
# Professor: Nikolaos Papanikolopoulos
#===============================================================================



def new_matrix(n):
    
    w = []
    for i in range(0, n):
        temp = []
        for j in range(0, n):
            temp.append(0)

        w.append(temp)
        
    return w





class UF:
        __id = []
        __count = 0

        def __init__(self, n):
                self.__count = n

                for i in range(0, n):
                        self.__id.append(i)
                        #print self.__id

        def print_id(self):
                return self.__id
        
        def count(self):
                return self.__count



        def find(self, p):
                while p != self.__id[p]:
                        p = self.__id[p]
                return p
                
        
        def connected(self, p, q):
                return find(p) == find(q)

        def union(self, p, q):
                i = self.find(p)
                j = self.find(q)
                if i == j:
                        return

                self.__id[i] = j
                __count = self.count() - 1



def kruskal(graph, w):

        q = [] # list to hold vertices

        u = []
        v = []
        
        A = []
        temp_set = UF(w)

        # from diagonol down, grab weights of edges
        for i in range(0, len(graph)):
                for j in range(i, len(graph)):
                        if graph[i][j] != 0:
                                t = (graph[i][j], i, j)
                                q.append(t)


        #sort edges
        q.sort()

        for i in range (0, len(q)):
                u.append(q[i][1])

        for i in range (0, len(q)):
                v.append(q[i][2])

                

        #print "sorted q:" ,q
        #print "u is:" ,u
        #print "v is:" ,v

        for e in range(0, len(q)):
                if temp_set.find(u[e]) != temp_set.find(v[e]):
                        A.append(q[e])
                        temp_set.union(u[e], v[e])

        #print "A is: ", A
        
        return A
                
        
        

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






# note: graph file must contain weights in the undirected adj. matrix
graphFile = open("graph_file.txt", "r") # get file

temp = [] # Temp is the matrix that Kruskal will be run on.

# split takes the line and splits the elements into seperate strings
# adds the line to the matrix
for line in graphFile:
        temp.append(line.split())

# converts the matrix of strings to ints
int_matrix(temp)




mst = kruskal(temp, len(temp))


final = new_matrix(len(mst) + 1)

#construct final adj. list
for i in range(0, len(mst)):
        u = mst[i][1]
        v = mst[i][2]
        final[v][u] = 1
        final[u][v] = 1
        

print "Final adj. matrix:"
print_matrix(final)




graphFile.close() # close file
