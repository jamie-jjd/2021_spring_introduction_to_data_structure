# alternative provided by TA 李旺陽
def Simulate(m, queries):
    res = []
    st = set()
    for op, v in queries:
        if op == 1:
            st.add(v)
        if op == 2:
            if v in st:
                st.remove(v)
        if op == 3:
            res.append( 1 if v in st else 0 )
    return res
