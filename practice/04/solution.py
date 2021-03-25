// provided by TA 李旺陽
#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'PerformOperationsOnLists' function below.
#
# The function is expected to return a LONG_INTEGER_ARRAY.
# The function accepts 2D_LONG_INTEGER_ARRAY operations as parameter.
#

def PerformOperationsOnLists(operations):
    L = [[], []]
    
    for op, id1, pos, id2, pos2 in operations:
        if op == 0:
            L[id1].insert(pos, id2)
            pass
        elif op == 1:
            L[id1].pop(pos)
        else:
            # get slice is O(n) in python ...
            P1 = L[id2][pos2:] 

            L[id2] = L[id2][:pos2]
            L[id1] = L[id1][:pos] + P1 + L[id1][pos:]
    return L[0] + L[1]

if __name__ == '__main__':
    #fptr = open(os.environ['OUTPUT_PATH'], 'w')
    fptr = open("L.py.ans", 'w')

    t = int(input().strip())

    for t_itr in range(t):
        m = int(input().strip())

        operations = []

        for _ in range(m):
            operations.append(list(map(int, input().rstrip().split())))

        concatenated_list = PerformOperationsOnLists(operations)

        fptr.write(' '.join(map(str, concatenated_list)))
        fptr.write('\n')

    fptr.close()
