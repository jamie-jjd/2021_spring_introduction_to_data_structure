# alternative provided by TA 李旺陽
def Simulate(m, queries):
    res = []
    dic = {}
    for op, a, b in queries:
        if op == 1:
            dic[a] = b
        elif op == 2:
            if a in dic:
                del dic[a]
        else:
            res.append( 0 if a not in dic else dic[a] )
    return res
