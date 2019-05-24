#===============================================================================
# Programming Assignment 1, part B
# Name: Chris Dang
# x500 Login: dangx225
# ID number: 5323765
# Course: CSCI 4041-011
# Professor: Nikolaos Papanikolopoulos
#===============================================================================
import collections

#string for testing
#sampleChar = "ffffeeeeeeeeefccccccccccccbbbbbbbbbbbbbddddddddddddddddaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
 


class node:
        __val = None    # val contains a number
        __name = None   # name contains a string, the char to be encoded
        __left = None
        __right = None

        def __str__(self):
                return "Char: {}. Occurs:{}".format(self.__name, self.__val)

        def __repr__(self):
                return "Char: {}. Occurs:{}".format(self.__name, self.__val) 
        
        def __init__(self, val, name = None): # node constructor
                self.__val = val
                self.__name = name
        
        # node setters, getters, and removes
        def set_val(self, val):
                self.__val = val
        
        def get_val(self):              
                return self.__val

        def set_name(self, name):
                self.__name = name
        
        def get_name(self):
                return self.__name
        
        def set_left(self, left):
                self.__left = left
        
        def get_left(self):
                return self.__left

        def remove_left(self):
                self.__left = None

        def set_right(self, right):
                self.__right = right
        
        def get_right(self):
                return self.__right

        def remove_right(self):
                self.__right = None

        # print content of node
        def printCont(self):
                print "  Val:", self.__val
                print " left:", self.__left
                print "right:", self.__right

        # print node for tree
        def printNode(self):
                print "       ", self.__val, "     "
                print self.__left, "     ", self.__right


def build_table(myStr):
        myList = collections.Counter(myStr)
        myList = myList.most_common()[::-1] # reverse

        newList = []
        for i in range(0, len(myList)):
                newList.append(node(myList[i][1],myList[i][0]))
        
        #for i in range(0, len(newList)):
        #        print newList[i]

   
        while len(newList) > 0:
                if len(newList) == 1:           # done?
                        return newList[0]       # return list
                else:
                        item1, item2 = newList[0], newList[1]
                        del newList[0:2]
                        bigNode = node(item1.get_val() + item2.get_val())
                        bigNode.set_left(item1)
                        bigNode.set_right(item2)
                        newList = sorted([bigNode] + newList, key = node.get_val)

# Read me please!
# Descrption of what display_codes was meant to do:
# Display codes was to use a list containing the keys with their values.
# Starting with the first element, it would recursilvely traverse the tree,
# appending '0' or '1' to the code variable if it went left or right, respectively.
# Once it found the key, it would stop traversal, display the code,
# remove the first item of the list, and continue with the redacted list.
# This would continue until empty.
              
##
##def display_codes(myStr, table):
##        myList = collections.Counter(myStr)
##        myList = myList.most_common()[::-1] # reverse
##
##        i = 0
##        while len(myList) != 0:
##                code = ""
##                if table[0].get_left() == myList[i][0]:
##                        code = code + "0"
##                else if table[0].get_right() == myList[i][0]:
##                        code = code + "1"
##                else:
##


charFile = open("char_info.txt")
myString = charFile.read() # read file and hope the memory doesn't run out.


# Display to show that the tree is correct in construction
build_table(myString).printNode()
build_table(myString).get_right().printNode()
build_table(myString).get_right().get_left().printNode()
build_table(myString).get_right().get_right().printNode()
build_table(myString).get_right().get_right().get_left().printNode()


charFile.close()

