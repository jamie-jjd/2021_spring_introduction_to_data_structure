#!/usr/bin/env python
# coding: utf-8




import heapq

# alternative 1
def HeapSort(A):
    heap = []
    for item in A:
        heapq.heappush(heap, item)
    output = []
    while len(heap) > 0:
        output.append(heapq.heappop(heap))
    return(output)

# alternative 2
def HeapSort(A):
    output = []
    heapq.heapify(A)
    while len(A) > 0:
        output.append(heapq.heappop(A))
    return(output)


def HeapSortInNondecreasingOrder(A):
    # Write your code here
    nd_heap = A[:]
    sorted_nd_heap = HeapSort(nd_heap)
    return(sorted_nd_heap)


def HeapSortInNonincreasingOrder(A):
    # Write your code here
    ni_heap = list(map(lambda x: x*-1, A))
    sorted_ni_heap = list(map(lambda x: x*-1, HeapSort(ni_heap)))
    return(sorted_ni_heap)






