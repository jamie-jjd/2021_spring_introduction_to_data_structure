// alternative provided by TA 李旺陽
void dfs(long v, const vector<vector<long>> &E, vector<bool> &used) {
    used[v] = true;
    for(long e:E[v])
        if(!used[e])
            dfs(e, E, used);
}

string Travle1(long n, long m, vector<vector<long>> edges) {
    vector<vector<long>> E(n);
    vector<long> deg(n);
    vector<bool> used(n);

    for(auto &e:edges) {
        E[e[0]].emplace_back(e[1]);
        E[e[1]].emplace_back(e[0]);
        deg[e[0]]++;
        deg[e[1]]++;
    }

    dfs(0, E, used);

    if ( any_of(deg.begin(), deg.end(), [](long i){ return i % 2 == 1; }) ||
         count(used.begin(), used.end(), false) > 0 )
        return "no";
    return "yes";
}

// alternative provided by TA 鄧晉杰
template <typename Graph>
long BFS (Graph const &graph)
{
  long count {};
  std::vector<bool> is_discovered(graph.size());
  std::deque<long> nodes;
  is_discovered[0] = true;
  nodes.emplace_back(0);
  while (!nodes.empty())
  {
    ++count;
    auto from {nodes.front()}; nodes.pop_front();
    for (auto const to : graph[from])
    {
      if (!is_discovered[to])
      {
        is_discovered[to] = true;
        nodes.emplace_back(to);
      }
    }
  }
  return count;
}

std::string Travle1 (long n, long m, std::vector<std::vector<long>> edges)
{
  std::vector<std::vector<long>> graph(n);
  for (auto const &edge : edges)
  {
    graph[edge[0]].emplace_back(edge[1]);
    graph[edge[1]].emplace_back(edge[0]);
  }
  for (auto neighbors : graph)
  {
    if ((neighbors.size() == 0) || (neighbors.size() % 2 == 1))
    {
      return "no";
    }
  }
  if (BFS(graph) != n)
  {
    return "no";
  }
  return "yes";
}
