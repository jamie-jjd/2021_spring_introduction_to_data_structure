# alternative provided by TA 李旺陽
def CalculateMaximalAmount(n, root, edges, S, k, R):
    E = [ [] for _ in range(n) ]
    for a, b in edges:
        E[a].append(b)
        E[b].append(a)

    def dfs(v, pa):
        for e in E[v]:
            if e != pa:
                S[v] += dfs(e, v)
        return S[v]
    dfs(root, root)
    ans = 0
    for a in R:
        ans = max(ans, S[a])
    return ans
