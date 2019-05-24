#===============================================================================
# Programming Assignment 1, part A
# Name: Chris Dang
# x500 Login: dangx225
# ID number: 5323765
# Course: CSCI 4041-011
# Professor: Nikolaos Papanikolopoulos
#===============================================================================
import math #import for floor function


class customer:
        __val = None
        __name = ""

        def __str__(self):
                return "Name = {}Priority Value = {}\n".format(self.__name, self.__val) 
        
        def __init__(self, val, name): # constructor
                self.__val = val
                self.__name = name
                
        def set_val(self, val):
                self.__val = val
                
        def get_val(self):
                return self.__val

        def set_name(self, name):
                self.__name = name
                
        def get_name(self):
                return self.__name

        def printName(self):
                print self.__name

        # overloaded functions for comparisons
        def __lt__(self, item): # overloaded <
                return self.__val < item
        
        def __gt__(self, item): # overloaded >
                return self.__val > item

        def __le__(self, item): # overloaded <=
                if isinstance(item, customer):
                        return self.__val <= item.__val
                elif isinstance(item, (int, float)):
                        return self.__val <= item
                else:
                        return NotImplemented
                        
        def __ge__(self, item): # overloaded >=
                if isinstance(item, customer):
                        return self.__val >= item.__val
                elif isinstance(item, (int, float)):
                        return self.__val >= item
                else:
                        return NotImplemented

# array based heap that similates a tree
# array is buffered with a 0 in the beginning for ease of implementation
class heap:
        __tree = []
        
        def __init__(self, theList):    # constructor
                self.__tree = [0] + theList

        def parent(self, index):
                return math.floor(i/2)

        def left(self, index):
                return 2 * index

        def right(self, index):
                return 2 * index + 1

        def heap_size(self):
                return len(self.__tree) - 1



        def print_names(self):          # print list of customer names
                for i in range(1 , self.heap_size()+1):
                        print self.__tree[i]

        # heapify based from notes and text book
        def heapify(self, index):
                l = self.left(index)
                r = self.right(index)

                # find largest amongst suubtree
                if l <= self.heap_size() and self.__tree[l] > self.__tree[index]: 
                        largest = l

                else:
                        largest = index

                if r <= self.heap_size() and self.__tree[r] > self.__tree[largest]:
                        largest = r

                
                if largest != index:
                        self.__tree[index], self.__tree[largest] = self.__tree[largest], self.__tree[index] # exchange
                        self.heapify(largest) # recur

        # build heap based from notes and text book
        def build_heap(self):
                for i in range(int(math.floor(self.heap_size()/2)), 0, -1):
                        self.heapify(i)

        # heap sort based from notes and text book
        def heap_sort(self):

                newList = []
                self.build_heap()
                for i in range(self.heap_size(), 0, -1):
                        newList.append(self.maximum())
                        self.__tree[1], self.__tree[i] = self.__tree[i], self.__tree[1]
                        del self.__tree[self.heap_size()]
                        self.heapify(1)
                        
                self.__tree = [0] + newList
                   
                        
        def insert(self, customer):
                self.__tree.append(customer)
                self.heap_sort()

        def maximum(self):
                return self.__tree[1]

        def extract_max(self):
                maxVal = self.maximum() # store maximum for return

                self.__tree[1], self.__tree[self.heap_size()] = self.__tree[self.heap_size()], self.__tree[1] # swap root to bottem
                del self.__tree[len(self.__tree) - 1] # delete the leaf that contains the root after swap
                self.heap_sort() # sort to restore heap property

                return maxVal



customersFile = open("customers_info.txt", "r") # get file
custList = []
count = 1
name = ""
val = 0
for line in customersFile:

        if count % 2 == 1:      # odd line number?
                name = line     # get the name
                count = count + 1

        else:                   # even line number?
                val = int(line) # get the priority value
                custList.append(customer(val, name)) # append to the list!
                count = count + 1

myHeap = heap(custList)
myHeap.build_heap()     
myHeap.heap_sort()

print "List of Customers According to their Priority:"
print "==============================================================================="
myHeap.print_names()




customersFile.close()
