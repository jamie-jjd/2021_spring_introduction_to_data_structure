// alternative provided by TA 李旺陽
long dfs(int v, int pa,const vector<vector<long>> &E, long &ans) {
    vector<long> deps;
    for (long e:E[v]) {
        if (e==pa)
            continue;
        deps.emplace_back(dfs(e, v, E, ans));
    }
    if (deps.size() == 0) {
        return 0;
    } else {
        sort(deps.begin(), deps.end(), greater<>());
        if (deps.size() >= 2 ) {
            ans = max(ans, deps[0] + deps[1] + 2);
        }
        ans = max(ans, deps[0] + 1);
        return deps[0] + 1;
    }
}

long Travle3(long n, vector<vector<long>> edges) {
    vector<vector<long>> E(n);

    for(auto &e:edges) {

        E[e[0]].emplace_back(e[1]);
        E[e[1]].emplace_back(e[0]);
    }

    long ans = 0;
    dfs(0, 0, E, ans);
    return ans;
}

// alternative provided by TA 鄧晉杰
template <typename Tree, typename Lengths>
void BFS (Tree const &tree, Lengths &lengths, long root)
{
  std::deque<long> nodes;
  std::vector<bool> is_discovered(tree.size());
  is_discovered[root] = true;
  nodes.emplace_back(root);
  while (!nodes.empty())
  {
    auto from {nodes.front()}; nodes.pop_front();
    for (auto const to : tree[from])
    {
      if (!is_discovered[to])
      {
        is_discovered[to] = true;
        nodes.emplace_back(to);
        lengths[to] = lengths[from] + 1;
      }
    }
  }
  return;
}

long Travle3 (long n, std::vector<std::vector<long>> edges)
{
  std::vector<std::vector<long>> tree(n);
  for (auto const &edge : edges)
  {
    tree[edge[0]].emplace_back(edge[1]);
    tree[edge[1]].emplace_back(edge[0]);
  }
  std::vector<long> lengths(n);
  for (long i {}; i != n; ++i)
  {
    if (tree[i].size() == 1)
    {
      BFS(tree, lengths, i);
      break;
    }
  }
  long max_index {};
  for (long i {}; i != n; ++i)
  {
    if (lengths[i] > lengths[max_index])
    {
      max_index = i;
    }
  }
  std::fill(lengths.begin(), lengths.end(), 0);
  BFS(tree, lengths, max_index);
  return *max_element(lengths.begin(), lengths.end());
}
