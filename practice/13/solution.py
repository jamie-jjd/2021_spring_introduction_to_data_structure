# alternative (binary search on suffix array) provided by TA 李旺陽
def lower_bound(sa, M, s):
    L, R = -1, len(sa) - 1
    if M[sa[-1]:] < s:
        return M[sa[-1]:]
    while L+1<R:
        mid = (L+R)//2
        if M[sa[mid]:] < s:
            L=mid
        else:
            R=mid
    return M[sa[R]:]

def Check(N, m, Ms):
    res = []
    sa = sorted(range(len(N)), key=lambda i: N[i:])
    for s in Ms:
        c = lower_bound(sa, N, s)
        if c[:min(len(c), len(s))] == s:
            res.append(1)
        else:
            res.append(0)
    return res

# alternative (suffix trie) provided by TA 鄧晉杰
class Trie:
    class Node:
        def __init__ (self):
            self.children = {}

    def __init__ (self):
        self.root = self.Node()

    def Insert (self, suffix):
        node = self.root
        for character in suffix:
            if character not in node.children:
                node.children[character] = self.Node()
            node = node.children[character]

    def Check (self, string):
        node = self.root
        for character in string:
            if character not in node.children:
                return 0
            node = node.children[character]
        return 1

def Check (N, m, Ms):
    trie = Trie()
    responses = []
    for i in range(len(N)):
        trie.Insert(N[i:])
    for M in Ms:
        responses.append(trie.Check(M))
    return responses
