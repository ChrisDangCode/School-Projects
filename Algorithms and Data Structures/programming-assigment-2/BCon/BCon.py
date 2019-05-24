#===============================================================================
# Programming Assignment 2, part C
# Name: Chris Dang
# x500 Login: dangx225
# ID number: 5323765
# Course: CSCI 4041-011
# Professor: Nikolaos Papanikolopoulos
#===============================================================================


def main():
    
    global graph
    graph = {}
    graph['a'] = ['b', 'c', 'd']
    graph['b'] = ['a', 'c']
    graph['c'] = ['a', 'b']
    graph['d'] = ['a']

    biconnect_comp(graph)






def biconnect_comp(graph):
    
    global count
    count = 0
    
    global visited
    visited = {}
    global d
    d = {}
    global low
    low = {}
    global parent
    parent = {}
    global stack
    stack = []


    for x in sorted(graph):
        visited[x] = False
        parent[x] = None

    for x in sorted(graph):
        if not visited[x]:
            DFS_visit(x)




def output_comp(u,v):
    print "New Binconneted Componented Found!"

    while True:
        e = stack.pop()
        print e

        if e == (u,v):
            break



def DFS_visit(u):

    global count
    
    visited[u] = True
    count = count + 1
    
    d[u] = count
    low[u] = d[u]


    
    for v in sorted(graph):
        if not visited[v]:
            stack.append((u,v))
            parent[v] = u
            DFS_visit(v)
            if low[v] >= d[u]:
                output_comp(u,v)
            low[u] = min(low[u],low[v])

        elif not parent[u] == v and d[v] < d[u]:
            stack.append((u,v))
            low[u] = min(low[u],d[v])
        






    
    #for v in 
main()





    
    
