#!/bin/python3

import os
import sys

#
# Complete the cookies function below.
#
import heapq
def cookies(k, A):
    trys = 0
    heapq.heapify(A)
    while len(A)>1 and A[0]<=k:
        a = A[0]
        heapq.heappop(A)
        b = A[0]
        heapq.heappop(A)
        heapq.heappush(A, a+2*b)
        trys = trys + 1
    return trys if A[0] >=k else -1

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    A = list(map(int, input().rstrip().split()))

    result = cookies(k, A)

    fptr.write(str(result) + '\n')

    fptr.close()
