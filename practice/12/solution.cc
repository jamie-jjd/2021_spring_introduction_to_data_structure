// alternative provided by TA 鄧晉杰
struct Trie
{
  struct Node
  {
    std::map<char, std::shared_ptr<Node>> children;
  };

  std::shared_ptr<Node> root;

  Trie (): root(std::make_shared<Node>()) {}

  template <typename StringIterator>
  void Insert (StringIterator it, StringIterator end)
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
    }
    return;
  }

  template <typename StringIterator>
  long Check (StringIterator it, StringIterator end)
  {
    auto node {root};
    while (it != end)
    {
      if (node != nullptr && node->children.find(*it) != node->children.end())
      {
        node = node->children[*it];
      }
      else
      {
        return 0;
      }
      ++it;
    }
    return 1;
  }
};

std::vector<long> PrefixMatch (long m, std::vector<std::vector<std::string>> operations)
{
  std::vector<long> responses;
  Trie trie;
  for (auto const &operation : operations)
  {
    auto const &opcode {operation[0]};
    auto const &key {operation[1]};
    if (opcode == "insert")
    {
      trie.Insert(key.begin(), key.end());
    }
    else
    {
      responses.emplace_back(trie.Check(key.begin(), key.end()));
    }
  }
  return responses;
}

// alternative provided by TA 李旺陽
struct node {
    node *next[10];

    node() {
        fill_n(next, 10, nullptr);
    }

    ~node() {
        for(auto p: next)
            if (p)
                delete p;
    }
};

void insert(node *head, const string &str) {
    for(char c: str) {
        if (head->next[c-'0'] == nullptr)
            head->next[c-'0'] = new node;
        head = head->next[c-'0'];
    }
}

long check(node *head, const string &str) {
    for(char c: str) {
        if (head->next[c-'0'] == nullptr)
            return 0;
        head = head->next[c-'0'];
    }
    return 1;
}

vector<long> PrefixMatch(long m, vector<vector<string>> operations) {
    vector<long> res;
    shared_ptr<node> trie(new node);

    for(auto op: operations) {
        if (op[0] == "insert")
            insert(trie.get(), op[1]);
        else if(op[0] == "check")
            res.emplace_back(check(trie.get(), op[1]));
    }

    return res;
}
