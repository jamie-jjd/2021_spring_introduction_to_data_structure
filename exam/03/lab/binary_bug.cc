// alternative provided by TA 鄧晉杰
struct Trie
{
  struct Node
  {
    long count;
    std::map<char, std::shared_ptr<Node>> children;
  };

  std::shared_ptr<Node> root;

  Trie (): root {std::make_shared<Node>()} {}

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
      ++(node->count);
      ++it;
    }
  }

  template <typename StringIterator>
  long Count (StringIterator it, StringIterator end)
  {
    auto node {root};
    while (it != end)
    {
      if ((node != nullptr) && (node->children.find(*it) != node->children.end()))
      {
        node = node->children[*it];
      }
      else
      {
        return 0;
      }
      ++it;
    }
    return node->count;
  }
};

std::vector<long> CountBug (long n, std::vector<std::string> C, long m, std::vector<std::string> B)
{
  std::vector<long> responses;
  Trie trie;
  for (auto &code : C)
  {
    for (auto it {code.begin()}; it != code.end(); ++it)
    {
      trie.Insert(it, code.end());
    }
  }
  for (auto &bug : B)
  {
    responses.push_back(trie.Count(bug.begin(), bug.end()));
  }
  return responses;
}
