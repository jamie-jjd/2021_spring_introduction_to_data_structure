# alternative provided by TA 蔡宗霖
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


def journeyToMoon(n, astronaut):
    adj_l = [[] for _ in range(n)]
    weight = [0] * n
    find = [False] * n

    for s, t in astronaut:
        adj_l[s].append(t)
        adj_l[t].append(s)

    group = []

    for i in range(n):
        if not find[i]:
            cost, members = BFS(adj_l, find, i, weight)
            group.append(members)

    output = 0
    count = sum(group)
    for i in group[:-1]:
        count -= i
        output = output + (i * count)
    return(output)
