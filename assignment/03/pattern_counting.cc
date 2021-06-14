// alternative 1 (prefix range on sorted suffixes) provided by TA 鄧晉杰
std::vector<long> Count (std::string B, long m, std::vector<std::string> Ps)
{
  std::vector<long> counts;
  std::vector<std::string> suffixes;
  for (size_t i {}; i != B.size(); ++i)
  {
    suffixes.emplace_back(B.substr(i));
  }
  std::sort(suffixes.begin(), suffixes.end());
  for (auto const &P : Ps)
  {
    auto prefix_range_begin {std::lower_bound(suffixes.begin(), suffixes.end(), P)};
    auto less_than
    {
      [] (std::string const &left, std::string const &right)
      {
        auto pair {std::mismatch(left.begin(), left.end(), right.begin(), right.end())};
        auto left_it {std::get<0>(pair)};
        auto right_it {std::get<1>(pair)};
        if (left_it != left.end() && right_it != right.end())
        {
          return (*left_it < *right_it);
        }
        return false;
      }
    };
    auto prefix_range_end {std::upper_bound(suffixes.begin(), suffixes.end(), P, less_than)};
    counts.emplace_back(std::distance(prefix_range_begin, prefix_range_end));
  }
  return counts;
}

// alternative 2 (prefix range on suffix trie) provided by TA 鄧晉杰
struct Trie
{
  struct Node
  {
    long count;
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
      ++node->count;
      ++it;
    }
    return;
  }

  template <typename PatternIterator>
  long Count (PatternIterator it, PatternIterator end)
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
    return node->count;
  }
};

std::vector<long> Count (std::string B, long m, std::vector<std::string> Ps)
{
  std::vector<long> counts;
  Trie suffix_trie;
  for (auto it {B.begin()}; it != B.end(); ++it)
  {
    suffix_trie.Insert(it, B.end());
  }
  for (auto const &P : Ps)
  {
    counts.emplace_back(suffix_trie.Count(P.begin(), P.end()));
  }
  return counts;
}

// alternative (prefix range on suffix array) provided by TA 李旺陽
vector<long> GetSA(const string &s) {
    vector<long> index(s.size());
    iota(index.begin(), index.end(), 0);
    sort(index.begin(), index.end(), [&s](long a, long b) {
        return strcmp(s.c_str()+a, s.c_str()+b) < 0;
    });
    return index;
}

vector<long> Count(string B, long m, vector<string> Ps) {
    vector<long> res;
    auto sa = GetSA(B);
    auto cmp = [&B](long v, const auto &s) {
        return B.c_str()+v < s;
    };
    for(const auto &s: Ps) {
        auto ed = s;
        ed.back()++;
        res.emplace_back(
            lower_bound(sa.begin(), sa.end(), ed, cmp) -
            lower_bound(sa.begin(), sa.end(), s, cmp));
    }
    return res;
}
