# alternative provided by TA 李旺陽
def path(root, v):
    res = []
    ptr = root
    while ptr != None:
        res.append(ptr)
        if v == ptr.info:
            break
        elif v < ptr.info:
            ptr = ptr.left
        else:
            ptr = ptr.right
    return res

def lca(root, v1, v2):
    p1 = path(root, v1)
    lca = None
    for v in path(root, v2):
        if v in p1:
            lca = v
    return lca
