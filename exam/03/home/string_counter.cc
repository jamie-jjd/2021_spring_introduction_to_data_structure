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
      if (node && (node->children.find(*it) != node->children.end()))
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

long Check1 (std::string S, long m, long k, std::vector<std::string> Ts)
{
  long count {};
  Trie trie;
  auto S_it {S.begin()};
  auto S_last {std::prev(S.end(), k - 1)};
  while (S_it != S_last)
  {
    auto it {S_it};
    auto last {std::next(it, k)};
    while (it != last)
    {
      trie.Insert(it, last);
      ++it;
    }
    ++S_it;
  }
  for (auto const &T : Ts)
  {
    count += trie.Count(T.begin(), T.end());
  }
  return count;
}
