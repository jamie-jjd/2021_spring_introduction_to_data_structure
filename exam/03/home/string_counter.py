# alternative provided by TA 鄧晉杰
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

def Check1 (S, m, k, Ts):
    count = 0
    trie = Trie()
    for i in range(len(S) - k + 1):
        trie.Insert(S[i:i+k])
    for T in Ts:
        count += trie.Count(T)
    return count
