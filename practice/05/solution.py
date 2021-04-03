// alternative provided by TA 李旺陽
#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'CalculateIndegreesAndOutdegrees' function below.
#
# The function is expected to return a 2D_LONG_INTEGER_ARRAY.
# The function accepts following parameters:
#  1. LONG_INTEGER nodes_size
#  2. 2D_LONG_INTEGER_ARRAY edges
#

def CalculateIndegreesAndOutdegrees(nodes_size, edges):
    # Write your code here
    indeg = [0]*nodes_size
    outdeg = [0]*nodes_size
    for u,v in edges:
        indeg[v] += 1
        outdeg[u] += 1
    return [indeg, outdeg]

if __name__ == '__main__':
    fptr = open("acpy.ans", 'w')

    testcases_size = int(input().strip())

    for testcases_size_itr in range(testcases_size):
        nodes_size = int(input().strip())

        edges_size = int(input().strip())

        edges = []

        for _ in range(edges_size):
            edges.append(list(map(int, input().rstrip().split())))

        indegrees_and_outdegrees = CalculateIndegreesAndOutdegrees(nodes_size, edges)

        fptr.write('\n'.join([' '.join(map(str, x)) for x in indegrees_and_outdegrees]))
        fptr.write('\n')

    fptr.close()
