# alternative provided by TA 李旺陽
import heapq
def KthElements(k, n, a):
    # Write your code here
    a = [-x for x in a]
    heap = a[0:k]

    heapq.heapify(heap)
    ans = [-heap[0]]

    for i in a[k:]:
        heapq.heappushpop(heap, i)
        ans.append(-heap[0])

    return ans
