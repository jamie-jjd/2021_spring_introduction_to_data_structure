# alternative provided by TA 李旺陽
class Node:
    def __init__(self):
        self.next = dict()

def insert(trie: Node, s: str):
    ptr = trie
    for c in s:
        if c not in ptr.next:
            ptr.next[c] = Node()
        ptr = ptr.next[c]

def check(trie: Node, s: str):
    ptr = trie
    for c in s:
        if c not in ptr.next:
            return 0
        ptr = ptr.next[c]
    return 1

def PrefixMatch(m, operations):
    trie = Node()
    res = []
    for op, v in operations:
        if op == "insert":
            insert(trie, v)
        elif op == "check":
            res.append(check(trie, v))
    return res
