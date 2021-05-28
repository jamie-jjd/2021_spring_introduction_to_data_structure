# alternative provided by TA 李旺陽
from collections import deque
def Travle3(n, edges):
    E = [ [] for _ in range(n) ]
    for a, b in edges:
        E[a].append(b)
        E[b].append(a)

    def BFS(x):
        dist = [ None for _ in range(n) ]
        qu = deque()
        qu.append(x)
        dist[x] = 0
        while len(qu) > 0:
            v = qu.popleft()
            for e in E[v]:
                if dist[e] == None:
                    dist[e] = dist[v] + 1
                    qu.append(e)
        return dist
    d1 = BFS(0)
    fp = d1.index(max(d1))
    return max(BFS(fp))
