// alternative 1 (recursive DFS) provided by TA 鄧晉杰
template <typename Tree, typename Assets>
void RecursiveDFS (Tree const &tree, Assets &assets, long from)
{
  for (auto to : tree[from])
  {
    RecursiveDFS(tree, assets, to);
    assets[from] += assets[to];
  }
  return;
}

long CalculateGangAsset
(
  long n,
  long root_id,
  std::vector<std::vector<long>> edges,
  vector<long> assets
)
{
  std::vector<std::vector<long>> tree(n);
  for (auto const &edge : edges)
  {
    tree[edge[0]].emplace_back(edge[1]);
  }
  RecursiveDFS(tree, assets, root_id);
  return *max_element(assets.begin(), assets.end());
}

// alternative 2 (Iterative DFS) provided by TA 鄧晉杰
template <typename Tree, typename Assets>
void IterativeDFS (Tree const &tree, Assets &assets, long root_id)
{
  std::deque<long> node;
  std::vector<bool> is_forward(tree.size(), true);
  node.emplace_back(root_id);
  while (!node.empty())
  {
    auto node_id {node.back()};
    if (is_forward[node_id])
    {
      is_forward[node_id] = false;
      for (auto to : tree[node_id])
      {
        node.emplace_back(to);
      }
    }
    else
    {
      for (auto to : tree[node_id])
      {
        assets[node_id] += assets[to];
      }
      node.pop_back();
    }
  }
  return;
}

long CalculateGangAsset
(
  long n,
  long root_id,
  std::vector<std::vector<long>> edges,
  vector<long> assets
)
{
  std::vector<std::vector<long>> tree(n);
  for (auto const &edge : edges)
  {
    tree[edge[0]].emplace_back(edge[1]);
  }
  IterativeDFS(tree, assets, root_id);
  return *max_element(assets.begin(), assets.end());
}
