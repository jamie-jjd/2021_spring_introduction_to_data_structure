# alternative provided by TA 蔡宗霖
from collections import deque
def BFS(graph, find, start, weight):
    cost = 0
    member = 1
    queue = deque([])
    find[start] = True
    queue.append(start)
    while len(queue) > 0:
        v = queue.popleft()
        cost += weight[v]
        for nei in graph[v]:
            if not find[nei]:
                find[nei] = True
                queue.append(nei)
                member += 1
    return(cost, member)

def CalculateCosts(n, m, roads):
    adj_l = [[] for _ in range(n)]
    weight = [0] * n
    find = [False] * n

    for s, t, w in roads:
        adj_l[s].append(t)
        adj_l[t].append(s)
        weight[s] += w

    output = []
    for i in range(n):
        if not find[i]:
            cost, members = BFS(adj_l, find, i, weight)
            output.append(cost)
    return(sorted(output))
