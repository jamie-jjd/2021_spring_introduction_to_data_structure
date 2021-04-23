// alternative 1 (BFS) provided by TA 鄧晉杰
template <typename Graph, typename IsDiscovered>
void BFS
(
  Graph const &graph,
  IsDiscovered &is_discovered,
  long const source
)
{
  std::deque<long> nodes;
  is_discovered[source] = true;
  nodes.emplace_back(source);
  while (!nodes.empty())
  {
    auto const from {nodes.front()}; nodes.pop_front();
    for (auto const to : graph[from])
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

string CheckIfConnected
(
  long nodes_size,
  std::vector<std::vector<long>> edges,
  long x,
  long y
)
{
  std::vector<std::vector<long>> graph(nodes_size);
  for (auto const &edge : edges)
  {
    graph[edge[0]].emplace_back(edge[1]);
    graph[edge[1]].emplace_back(edge[0]);
  }
  std::vector<bool> is_discovered(nodes_size, false);
  BFS(graph, is_discovered, x);
  if (is_discovered[y])
  {
    return "yes";
  }
  return "no";
}

// alternative 2 (DFS) provided by TA 鄧晉杰
template <typename Graph, typename IsVisited>
void DFS
(
  Graph const &graph,
  IsVisited &is_visited,
  long const source
)
{
  std::deque<long> nodes;
  nodes.emplace_back(source);
  while (!nodes.empty())
  {
    auto const from {nodes.back()};
    nodes.pop_back();
    if (!is_visited[from])
    {
      is_visited[from] = true;
      for (auto const &to : graph[from])
      {
        nodes.emplace_back(to);
      }
    }
  }
  return;
}

string CheckIfConnected
(
  long nodes_size,
  std::vector<std::vector<long>> edges,
  long x,
  long y
)
{
  std::vector<std::vector<long>> graph(nodes_size);
  for (auto const &edge : edges)
  {
    graph[edge[0]].emplace_back(edge[1]);
    graph[edge[1]].emplace_back(edge[0]);
  }
  std::vector<bool> is_visited(nodes_size, false);
  DFS(graph, is_visited, x);
  if (is_visited[y])
  {
    return "yes";
  }
  return "no";
}

// alternative 3 (DFS - recursive version) provided by TA 鄧晉杰
/* note: this alternative is limited if depth of recursion is too large */
template <typename Graph, typename IsVisited>
void RecursiveDFS
(
  Graph const &graph,
  IsVisited &is_visited,
  long const from
)
{
  is_visited[from] = true;
  for (auto const &to : graph[from])
  {
    if (!is_visited[to])
    {
      RecursiveDFS(graph, is_visited, to);
    }
  }
  return;
}

string CheckIfConnected
(
  long nodes_size,
  std::vector<std::vector<long>> edges,
  long x,
  long y
)
{
  std::vector<std::vector<long>> graph(nodes_size);
  for (auto const &edge : edges)
  {
    graph[edge[0]].emplace_back(edge[1]);
    graph[edge[1]].emplace_back(edge[0]);
  }
  std::vector<bool> is_visited(nodes_size, false);
  RecursiveDFS(graph, is_visited, x);
  if (is_visited[y])
  {
    return "yes";
  }
  return "no";
}

// alternative provided by TA 李旺陽
string CheckIfConnected(long nodes_size, vector<vector<long>> edges, long x, long y) {

    vector<vector<int>> E(nodes_size);
    for(auto vec:edges) {
        int s = vec[0];
        int e = vec[1];
        E[s].emplace_back(e);
        E[e].emplace_back(s);
    }

    vector<bool> used(nodes_size, false);
    stack<int> st;

    st.emplace(x);
    used[x] = true;

    while (!st.empty()) {
        int s = st.top();
        st.pop();

        for(int e:E[s]) {
            if(!used[e]) {
                st.emplace(e);
                used[e] = true;
            }
        }
    }

    return used[y] ? "yes" : "no";

}
