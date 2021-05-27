/* alternative 1 (recursive DFS) provided by TA 鄧晉杰 */
template
<
  typename Tree,
  typename IsVisited,
  typename Amounts
>
void RecursiveDFS
(
  Tree const &tree,
  IsVisited &is_visited,
  Amounts &amounts,
  long from
)
{
  is_visited[from] = true;
  for (auto to : tree[from])
  {
    if (!is_visited[to])
    {
      RecursiveDFS(tree, is_visited, amounts, to);
      amounts[from] += amounts[to];
    }
  }
  return;
}

long CalculateMaximalAmount
(
  long n,
  long root,
  vector<vector<long>> edges,
  vector<long> S,
  long k,
  vector<long> R
)
{
  std::vector<std::vector<long>> tree(n);
  for (auto const &edge : edges)
  {
    tree[edge[0]].emplace_back(edge[1]);
    tree[edge[1]].emplace_back(edge[0]);
  }
  std::vector<bool> is_visited(n);
  RecursiveDFS(tree, is_visited, S, root);
  long max {};
  for (long i {}; i != k; ++i)
  {
    if (S[R[i]] > max)
    {
      max = S[R[i]];
    }
  }
  return max;
}

/* alternative 2 (iterative DFS) provided by TA 鄧晉杰 */
template
<
  typename Tree,
  typename Amounts
>
void IterativeDFS
(
  Tree const &tree,
  Amounts &amounts,
  long root
)
{
  std::deque<long> nodes;
  std::vector<bool> is_forward(tree.size());
  nodes.emplace_back(root);
  while (!nodes.empty())
  {
    auto from {nodes.back()};
    if (!is_forward[from])
    {
      is_forward[from] = true;
      for (auto to : tree[from])
      {
        if (!is_forward[to])
        {
          nodes.emplace_back(to);
        }
      }
    }
    else
    {
      is_forward[from] = false;
      for (auto to : tree[from])
      {
        if (!is_forward[to])
        {
          amounts[from] += amounts[to];
        }
      }
      nodes.pop_back();
    }
  }
  return;
}

long CalculateMaximalAmount
(
  long n,
  long root,
  vector<vector<long>> edges,
  vector<long> S,
  long k,
  vector<long> R
)
{
  std::vector<std::vector<long>> tree(n);
  for (auto const &edge : edges)
  {
    tree[edge[0]].emplace_back(edge[1]);
    tree[edge[1]].emplace_back(edge[0]);
  }
  IterativeDFS(tree, S, root);
  long max {};
  for (long i {}; i != k; ++i)
  {
    if (S[R[i]] > max)
    {
      max = S[R[i]];
    }
  }
  return max;
}

/* alternative (recursive DFS) provided by TA 李旺陽 */
long dfs (long v, long pa, const vector<vector<long>> &edges, vector<long> &S) {
    for(auto e:edges[v])
        if(e!=pa)
            S[v] += dfs(e, v, edges, S);
    return S[v];
}

long CalculateMaximalAmount(long n, long root, vector<vector<long>> edges, vector<long> S, long k, vector<long> R) {
    vector<vector<long>> E(n);
    for (auto e:edges) {
        E[e[0]].emplace_back(e[1]);
        E[e[1]].emplace_back(e[0]);
    }
    dfs(root, root, E, S);
    long ans = 0;
    for(auto id:R)
        ans = max(ans, S[id]);
    return ans;
}
