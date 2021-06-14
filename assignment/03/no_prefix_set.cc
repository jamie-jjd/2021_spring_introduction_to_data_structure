// alternative provided by TA 鄧晉杰
struct Trie
{
  struct Node
  {
    std::map<char, std::shared_ptr<Node>> children;
  };

  std::shared_ptr<Node> root;

  Trie (): root(std::make_shared<Node>()) {}

  template <typename WordIterator>
  bool IsPrefix (WordIterator it, WordIterator end)
  {
    auto node {root};
    while (it != end)
    {
      if (node->children.find(*it) == node->children.end())
      {
        node->children[*it] = std::make_shared<Node>();
      }
      node = node->children[*it];
      ++it;
      if (node->children.find('$') != node->children.end())
      {
        return true;
      }
    }
    if (!node->children.empty())
    {
      return true;
    }
    node->children['$'] = std::make_shared<Node>();
    return false;
  }
};

void noPrefix (std::vector<std::string> words)
{
  Trie trie;
  for (auto const &word : words)
  {
    if (trie.IsPrefix(word.begin(), word.end()))
    {
      std::cout << "BAD SET\n";
      std::cout << word << "\n";
      return;
    }
  }
  std::cout << "GOOD SET\n";
  return;
}

// alternative provided by TA 李旺陽
struct node {
    node *next['j'-'a'+1]; // size = 10
    bool flag;

    node() {
        fill_n(next, 10, nullptr);
        flag = false;
    }

    ~node() {
        for(auto p: next)
            if (p)
                delete p;
    }
};

bool insert(node *head, const string &str) {
    bool lastNull = false;
    for(char c: str) {
        lastNull = false;
        if (head->next[c-'a'] == nullptr) {
            head->next[c-'a'] = new node;
            lastNull = true;
        }
        if (head->flag) return false;
        head = head->next[c-'a'];
    }
    if (!lastNull)
        return false;
    head->flag = true;
    return true;
}

void noPrefix(vector<string> words) {
    shared_ptr<node> trie(new node);
    for(auto s:words) {
        if (!insert(trie.get(), s)) {
            cout << "BAD SET\n" << s << '\n';
            return ;
        }
    }
    cout << "GOOD SET\n";
}
