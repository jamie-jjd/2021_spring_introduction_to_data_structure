/* alternative 1 (BFS) provided by TA 鄧晉杰 */
template <typename Graph, typename IsDiscovered>
void BFS
(
  Graph const &graph,
  IsDiscovered &is_discovered,
  long source
)
{
  std::deque<long> nodes;
  nodes.emplace_back(source);
  is_discovered[source] = true;
  while (!nodes.empty())
  {
    auto from {nodes.front()};
    nodes.pop_front();
    for (auto to : graph[from])
    {
      if (!is_discovered[to])
      {
        is_discovered[to] = true;
        nodes.emplace_back(to);
      }
    }
  }
  return;
}

long GazeIntoAbyss
(
  long n,
  long m,
  std::vector<std::vector<long>> edges,
  long s,
  long k,
  std::vector<long> L
)
{
  std::vector<std::vector<long>> graph(n);
  for (auto const &edge : edges)
  {
    graph[edge[1]].emplace_back(edge[0]);
  }
  std::vector<bool> is_discovered(n);
  BFS(graph, is_discovered, s);
  long amount {};
  for (auto l : L)
  {
    amount += is_discovered[l];
  }
  return amount;
}

/* alternative 2 (DFS) provided by TA 鄧晉杰 */
template <typename Graph, typename IsVisited>
void DFS
(
  Graph const &graph,
  IsVisited &is_visited,
  long from
)
{
  is_visited[from] = true;
  for (auto to : graph[from])
  {
    if (!is_visited[to])
    {
      DFS(graph, is_visited, to);
    }
  }
  return;
}

long GazeIntoAbyss
(
  long n,
  long m,
  std::vector<std::vector<long>> edges,
  long s,
  long k,
  std::vector<long> L
)
{
  std::vector<std::vector<long>> graph(n);
  for (auto const &edge : edges)
  {
    graph[edge[1]].emplace_back(edge[0]);
  }
  std::vector<bool> is_visited(n);
  DFS(graph, is_visited, s);
  long amount {};
  for (auto l : L)
  {
    amount += is_visited[l];
  }
  return amount;
}

// alternative provided by TA 李旺陽
long GazeIntoAbyss(long n, long m, vector<vector<long>> edges, long s, long k, vector<long> L) {
    vector<vector<long>> E(n);
    for (auto e:edges) {
        E[e[1]].emplace_back(e[0]); // build invert edge here
    }
    stack<long> st;
    vector<bool> used(n, false);

    st.emplace(s);
    used[s] = true;

    while (!st.empty()) {
        int v = st.top();
        st.pop();
        for(auto e:E[v]){
            if (!used[e]) {
                used[e] = true;
                st.emplace(e);
            }
        }
    }

    int ans = 0;
    for(auto u:L)
        if (used[u])
            ans++;
    return ans;
}
