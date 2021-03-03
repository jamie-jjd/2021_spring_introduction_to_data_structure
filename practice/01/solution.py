#!/usr/bin/env python
# coding: utf-8



from bisect import bisect_left 

def Search(A, Q):
    # Write your code here
    output = []
    A.sort()
    for element in Q:
        i = bisect_left(A, element)
        if i != len(A) and A[i] == element:
            output.append('yes')
        else:
            output.append('no')
    return(output)

