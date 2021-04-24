# alternative provided by TA 李旺陽
import heapq
def SimulateBankCounters(k, instructions):
    c = [ [] for _ in range(k) ]
    N = 1
    for op, A, B in instructions:
        if op == 1:
            heapq.heappush(c[A], N)
            N = N + 1
        elif op == 2:
            heapq.heappop(c[A])
        else: # op== 3
            c[B] += c[A]
            c[A] = []
            heapq.heapify(c[B])
    return [ ( x[0] if len(x)>0 else -1 ) for x in c ]
