# alternative provided by TA 李旺陽
import itertools
def Travle2(n, m, edges):
    M = [ [False]*n for _ in range(n)  ]
    for a, b in edges:
        M[a][b] = M[b][a] = True
    for path in list(itertools.permutations(range(n))):
        Flag = True
        for i in range(n):
            Flag = Flag and M[path[i]][path[(i+1)%n]]
        if Flag:
            return "yes"
    return "no"
