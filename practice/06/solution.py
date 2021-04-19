# alternative (DFS) provided by TA 李旺陽
def CheckIfConnected(nodes_size, edges, x, y):
    E = [ [] for _ in range(nodes_size) ]
    used = [False] * nodes_size
    stack = []

    for s, t in edges:
        E[s].append(t)
        E[t].append(s)

    used[x] = True
    stack.append(x)

    while len(stack) > 0 :
        s = stack.pop()
        for e in E[s]:
            if not used[e]:
                used[e] = True
                stack.append(e)
    return "yes" if used[y] else "no"

# alternative (BFS) provided by TA 鄧晉杰
from collections import deque
def CheckIfConnected (nodes_size, edges, x, y):
    graph = [ [] for _ in range(nodes_size) ]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)
    is_discovered = [False] * nodes_size
    nodes = deque([x]) # queue of nodes
    is_discovered[x] = True
    while len(nodes) > 0 :
        u = nodes.popleft()
        for v in graph[u]:
            if not is_discovered[v]:
                is_discovered[v] = True
                nodes.append(v)
    return "yes" if is_discovered[y] else "no"

# alternative (recursive DFS) provided by TA 鄧晉杰
# note: this alternative is limited if depth of recursion is too large
def DFS (graph, is_discovered, u):
    is_discovered[u] = True
    for v in graph[u]:
        if not is_discovered[v]:
            DFS(graph, is_discovered, v)

def CheckIfConnected (nodes_size, edges, x, y):
    graph = [ [] for _ in range(nodes_size) ]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)
    is_discovered = [False] * nodes_size
    DFS(graph, is_discovered, x)
    return "yes" if is_discovered[y] else "no"
