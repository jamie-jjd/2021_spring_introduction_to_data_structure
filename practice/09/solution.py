# alternative provided by TA 李旺陽
class Node:
    def __init__(self, v):
        self.v = v
        self.left = None
        self.right = None

def insert(n: Node, v):
    if n is None:
        return Node(v)
    if v < n.v:
        n.left = insert(n.left, v)
    elif n.v < v:
        n.right = insert(n.right, v)
    return n

def find(n: Node, v):
    if n is None:
        return False
    elif v == n.v:
        return True
    elif v < n.v:
        return find(n.left, v)
    return find(n.right, v)

def pre(n: Node, v):
    now = n
    pre = 0
    while now is not None:
        if now.v < v:
            pre = now.v
            now = now.right
        else:
            now = now.left
    return pre

def succ(n: Node, v):
    now = n
    succ = 0
    while now is not None:
        if v < now.v:
            succ = now.v
            now = now.left
        else:
            now = now.right
    return succ

def Min(n: Node):
    if n is None:
        return 0
    now = n
    while now.left is not None:
        now = now.left
    return now.v

def Max(n: Node):
    if n is None:
        return 0
    now = n
    while now.right is not None:
        now = now.right
    return now.v

def BinarySearchTreeSimulation(m, queries):
    res = []
    head = None
    for L in queries:
        if L[0] == 1:
            head = insert(head, L[1])
        elif L[0] == 2:
            res.append( 1 if find(head, L[1]) else 0 )
        elif L[0] == 3:
            res.append(pre(head, L[1]))
        elif L[0] == 4:
            res.append(succ(head, L[1]))
        elif L[0] == 5:
            res.append(Min(head))
        elif L[0] == 6:
            res.append(Max(head))
    return res
