#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'TopKIntegerSequence' function below.
#
# The function is expected to return a LONG_INTEGER_ARRAY.
# The function accepts 2D_LONG_INTEGER_ARRAY matrix as parameter.
#
import heapq
def TopKIntegerSequence(matrix):
    # Write your code here
    H = []
    ans = []

    szlimit = len(matrix)
    for row in matrix:
        for e in row:
            heapq.heappush(H, e)
        ans.append(heapq.heappop(H))

    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        k = int(input().strip())

        n = int(input().strip())

        matrix = []

        for _ in range(k):
            matrix.append(list(map(int, input().rstrip().split())))

        top_k_integer_sequence = TopKIntegerSequence(matrix)

        fptr.write(' '.join(map(str, top_k_integer_sequence)))
        fptr.write('\n')

    fptr.close()
