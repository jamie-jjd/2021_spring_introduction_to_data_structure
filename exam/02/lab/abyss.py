# alternative provided by TA 李旺陽
def GazeIntoAbyss(n, m, edges, s, k, L):
    E = [ [] for _ in range(n) ]
    Used = [ False for _ in range(n) ]
    for a, b in edges:
        E[b].append(a) # build invert edge here

    st = [s]
    Used[s] = True
    while len(st)>0:
        v = st.pop()
        for e in E[v]:
            if not Used[e]:
                Used[e] = True
                st.append(e)

    ans = 0
    for u in L:
        if Used[u]:
            ans = ans + 1
    return ans
