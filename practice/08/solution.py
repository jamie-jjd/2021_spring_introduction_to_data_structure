# alternative providede by TA 李旺陽
def CheckGraph(n, m, edges):
    E = [ [] for _ in range(n) ]
    InDeg = [ 0 for _ in range(n) ]
    st = []

    for s,e in edges:
        E[s].append(e)
        InDeg[e] = InDeg[e] + 1
    for i in range(n):
        if InDeg[i] == 0:
            st.append(i)

    cnt = 0
    while len(st) > 0:
        s = st.pop()
        cnt = cnt + 1;

        for e in E[s]:
            InDeg[e] = InDeg[e] - 1
            if InDeg[e] == 0:
                st.append(e)

    return "yes" if cnt == n else "no"
