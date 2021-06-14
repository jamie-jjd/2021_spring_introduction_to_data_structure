# alternative (prefix range on suffix array) provided by TA 李旺陽
def lower_bound(sa, M, s):
    L, R = -1, len(sa) - 1
    if M[sa[-1]:] < s:
        return len(sa)
    while L+1<R:
        mid = (L+R)//2
        if M[sa[mid]:] < s:
            L=mid
        else:
            R=mid
    return R

def Count(N, m, Ms):
    res = []
    sa = sorted(range(len(N)), key=lambda i: N[i:])
    for s in Ms:
        ed = s[:-1] + chr(ord(s[-1])+1)
        res.append(lower_bound(sa, N, ed) - lower_bound(sa, N, s))
    return res

# alternative (suffix trie) provided by TA 鄧晉杰
class Trie:
    class Node:
        def __init__ (self):
            self.count = 0
            self.children = {}

    def __init__ (self):
        self.root = self.Node()

    def Insert (self, suffix):
        node = self.root
        for character in suffix:
            if character not in node.children:
                node.children[character] = self.Node()
            node = node.children[character]
            node.count += 1

    def Count (self, string):
        node = self.root
        for character in string:
            if character not in node.children:
                return 0
            node = node.children[character]
        return node.count

def Count (N, m, Ms):
    responses = []
    trie = Trie()
    for i in range(len(N)):
        trie.Insert(N[i:])
    for M in Ms:
        responses.append(trie.Count(M))
    return responses
