#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'getMax' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts STRING_ARRAY operations as parameter.
#

def getMax(operations):
    # Write your code here
    stack = []
    ans = []

    for op in operations:
        if op[0] == '1':
            num = int(op[1:])
            if len(stack) == 0:
                stack.append(num)
            else:
                stack.append(max(num, stack[-1]))
        elif op[0] == '2':
            stack.pop()
        else:
            ans.append(stack[-1])

    return ans
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    ops = []

    for _ in range(n):
        ops_item = input()
        ops.append(ops_item)

    res = getMax(ops)

    fptr.write('\n'.join(map(str, res)))
    fptr.write('\n')

    fptr.close()
