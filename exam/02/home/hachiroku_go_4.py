# alternative provided by TA 李旺陽
def Travle4(n, m, edges):
    E = [ [] for _ in range(n) ]
    deg = [ 0 for _ in range(n) ]
    for a, b in edges:
        E[a].append(b)
        deg[b] = deg[b] + 1

    tlist = []
    st = []

    for i in range(n):
        if deg[i] == 0:
            st.append(i)
    while len(st)>0:
        v = st.pop()
        tlist.append(v)
        for e in E[v]:
            deg[e] = deg[e] - 1
            if deg[e] == 0:
                st.append(e)

    dist = [ 0 for _ in range(n) ]
    for v in reversed(tlist):
        for e in E[v]:
            dist[v] = max(dist[v], 1+dist[e])

    return max(dist)
