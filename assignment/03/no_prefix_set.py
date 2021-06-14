# alternative provided by TA 李旺陽
class Node:
    def __init__(self):
        self.next = dict()
        self.flag = False

def insert(trie: Node, s: str):
    lastNull = False
    ptr = trie
    for c in s:
        lastNull = False
        if c not in ptr.next:
            ptr.next[c] = Node()
            lastNull = True
        if ptr.flag:
            return False
        ptr = ptr.next[c]
    if not lastNull:
        return False
    ptr.flag = True
    return True

def noPrefix(words):
    trie = Node()
    for s in words:
        if not insert(trie, s):
            print("BAD SET")
            print(s)
            return
    print("GOOD SET")
