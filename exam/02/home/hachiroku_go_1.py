# alternative provided by TA 李旺陽
def Travle1(n, m, edges):
    deg = [ 0 for _ in range(n) ]
    E = [ [] for _ in range(n) ]
    for a, b in edges:
        E[a].append(b)
        E[b].append(a)
        deg[a] = 1 - deg[a]
        deg[b] = 1 - deg[b]

    if 1 in deg:
        return "no"

    used = [ False for _ in range(n) ]
    st = [0]
    used[0] = True

    while len(st) > 0:
        v = st.pop()
        for e in E[v]:
            if not used[e]:
                used[e] = True
                st.append(e)
    return "yes" if False not in used else "no"
