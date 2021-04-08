#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'MergeKSortedSequences' function below.
#
# The function is expected to return a LONG_INTEGER_ARRAY.
# The function accepts 2D_LONG_INTEGER_ARRAY sequences as parameter.
#

# alternative 1
def MergeTwoSortedList(ListA, ListB):
    """
    A simple function that merges two sorted lists(increase) into one sorted list(increase)
    ListA and ListB must be a sorted list !!!
    """
    MergeList = []
    i = 0
    j = 0
    while( i < len(ListA) and j < len(ListB)):
        if ListA[i] < ListB[j]:
            MergeList.append(ListA[i])
            i += 1
        else:
            MergeList.append(ListB[j])
            j += 1
            
    if i < len(ListA):
        MergeList.extend(ListA[i:])
        
    if j < len(ListB):
        MergeList.extend(ListB[j:])

    return(MergeList)
            
        
    
def MergeKSortedSequences(sequences, n, k):
    # Write your code here
    output = sequences[0][::-1]
    for seq in sequences[1:]:
        output = MergeTwoSortedList(output, seq[::-1])
    return(output[::-1])


# alternative 2
def MergeKSortedSequences(sequences):
    res = []
    times = sum([len(x) for x in sequences])

    for _ in range(times):
        mn = 10**9
        for seq in sequences:
            if len(seq) > 0 and seq[-1] < mn:
                mn = seq[-1]
        res.append(mn)
        for seq in sequences:
            if len(seq) > 0 and seq[-1] == mn: 
                seq.pop()
                break

    return res[::-1]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        k = int(input().strip())

        n = int(input().strip())

        sequences = []

        for _ in range(k):
            sequences.append(list(map(int, input().rstrip().split())))

        merged_sequences = MergeKSortedSequences(sequences)

        fptr.write(' '.join(map(str, merged_sequences)))
        fptr.write('\n')

    fptr.close()
