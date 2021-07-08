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

def CountBug (n, C, m, B):
    responses = []
    trie = Trie()
    for code in C:
        for i in range(len(code)):
            trie.Insert(code[i:])
    for bug in B:
        responses.append(trie.Count(bug))
    return responses
