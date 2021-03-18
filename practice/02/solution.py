def MergeSort(A, compare):
    # Write your code here
    if len(A) > 1:
        mid = len(A) // 2
        left = A[:mid]
        right = A[mid:]
        MergeSort(left, compare)
        MergeSort(right, compare)
        l = 0
        r = 0
        p = 0
        while(l < len(left) and r < len(right)):
            if compare(left[l], right[r]):
                A[p] = left[l]
                l += 1
            else:
                A[p] = right[r]
                r += 1
            p += 1
        while(l < len(left)):
            A[p] = left[l]
            l += 1
            p += 1
        while(r < len(right)):
            A[p] = right[r]  
            r += 1
            p += 1
def MergeSortInNondecreasingOrder(A):
    de_buffer = A[:]
    MergeSort(de_buffer, lambda a, b : a < b)
    return(de_buffer)

def MergeSortInNonincreasingOrder(A):
    in_buffer = A[:]
    MergeSort(in_buffer, lambda a, b : a > b)
    return(in_buffer)