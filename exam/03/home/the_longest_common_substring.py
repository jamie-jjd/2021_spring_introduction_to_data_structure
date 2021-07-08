# alternative provided by TA 鄧晉杰
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

    def CommonPrefixLength (self, string):
        length = 0
        node = self.root
        for character in string:
            if character not in node.children:
                break
            node = node.children[character]
            length += 1
        return length

def LCS (S, T):
    max_length = 0
    trie = Trie()
    for i in range(len(S)):
        trie.Insert(S[i:])
    for i in range(len(T)):
        length = trie.CommonPrefixLength(T[i:])
        if max_length < length:
            max_length = length
    return max_length
