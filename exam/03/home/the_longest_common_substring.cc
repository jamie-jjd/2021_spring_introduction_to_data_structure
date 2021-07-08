// alternative provided by TA 鄧晉杰
struct Trie
{
  struct Node
  {
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
      ++it;
    }
  }

  template <typename StringIterator>
  long CommonPrefixLength (StringIterator it, StringIterator end)
  {
    long length {};
    auto node {root};
    while (it != end)
    {
      if (node && (node->children.find(*it) != node->children.end()))
      {
        ++length;
        node = node->children[*it];
      }
      else
      {
        break;
      }
      ++it;
    }
    return length;
  }
};

long LCS (std::string S, std::string T)
{
  long max_length {};
  Trie trie;
  for (auto it {S.begin()}; it != S.end(); ++it)
  {
    trie.Insert(it, S.end());
  }
  for (auto it {T.begin()}; it != T.end(); ++it)
  {
    long length = trie.CommonPrefixLength(it, T.end());
    if (max_length < length)
    {
      max_length = length;
    }
  }
  return max_length;
}
