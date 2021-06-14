// alternative 1 (binary search on sorted suffix) provided by TA 鄧晉杰
std::vector<long> Check (std::string N, long m, std::vector<std::string> Ms)
{
  std::vector<long> responses;
  std::vector<std::string> suffixes;
  for (size_t i {}; i != N.size(); ++i)
  {
    suffixes.emplace_back(N.substr(i));
  }
  std::sort(suffixes.begin(), suffixes.end());
  for (auto const &M : Ms)
  {
    auto prefix_range_begin {std::lower_bound(suffixes.begin(), suffixes.end(), M)};
    if (prefix_range_begin != suffixes.end())
    {
      auto M_it {std::get<0>(std::mismatch(M.begin(), M.end(), prefix_range_begin->begin(), prefix_range_begin->end()))};
      if (M_it == M.end())
      {
        responses.emplace_back(1);
      }
      else
      {
        responses.emplace_back(0);
      }
    }
    else
    {
      responses.emplace_back(0);
    }
  }
  return responses;
}

// alternative 2 (suffix trie) provided by TA 鄧晉杰
struct Trie
{
  struct Node
  {
    std::map<char, std::shared_ptr<Node>> children;
  };

  std::shared_ptr<Node> root;

  Trie (): root(std::make_shared<Node>()) {}

  template <typename PatternIterator>
  void Insert (PatternIterator it, PatternIterator end)
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

  template <typename PatternIterator>
  long Search (PatternIterator it, PatternIterator end)
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

std::vector<long> Check (std::string N, long m, std::vector<std::string> Ms)
{
  std::vector<long> responses;
  std::vector<std::string> suffixes;
  Trie suffix_trie;
  for (auto it {N.begin()}; it != N.end(); ++it)
  {
    suffix_trie.Insert(it, N.end());
  }
  for (auto const &M : Ms)
  {
    responses.emplace_back(suffix_trie.Search(M.begin(), M.end()));
  }
  return responses;
}

// alternative (binary search on suffix array) provided by TA 李旺陽

// Note: after c++17,
// you can use string_view to replace s.c_str()+a
// Both are faster way to get subsring s[a:]

vector<long> GetSA(const string &s) {
    vector<long> index(s.size());
    iota(index.begin(), index.end(), 0);
    sort(index.begin(), index.end(), [&s](long a, long b) {
        return strcmp(s.c_str()+a, s.c_str()+b) < 0;
    });
    return index;
}

vector<long> Check(string N, long m, vector<string> Ms) {
    auto sa = GetSA(N);
    vector<long>  res;
    for(const auto &s: Ms) {
        int index = *lower_bound(sa.begin(), sa.end(), s, [&N](long v, const auto &s) {
            return N.c_str()+v < s;
        });
        res.push_back(!strncmp(N.c_str()+index, s.c_str(), s.size()));
    }
    return res;
}
