// alternative provided by TA 李旺陽
long dfs(int v, const vector<vector<long>> &E, vector<long> &dp) {
    if (dp[v] == 0)
        for (int e:E[v])
            dp[v] = max(dp[v], 1+dfs(e, E, dp));
    return dp[v];
}

long Travle4(long n, long m, vector<vector<long>> edges) {
    vector<vector<long>> E(n);
    vector<long> dp(n, 0);
    vector<long> deg(n);

    for(auto &e:edges) {
        E[e[0]].emplace_back(e[1]);
        deg[e[1]]++;
    }
    for(int i=0;i<n;++i)
        if (deg[i] == 0)
            dfs(i, E, dp);
    return *max_element(dp.begin(), dp.end());
}

// alternative provided by TA 鄧晉杰
long Travle4 (long n, long m, std::vector<std::vector<long>> edges)
{
  std::vector<std::vector<long>> graph(n);
  std::vector<long> indegrees(n);
  for (auto const &edge : edges)
  {
    graph[edge[0]].emplace_back(edge[1]);
    ++indegrees[edge[1]];
  }
  std::vector<long> lengths(n);
  std::deque<long> nodes;
  for (long i {}; i != n; ++i)
  {
    if (indegrees[i] == 0)
    {
      nodes.emplace_back(i);
    }
  }
  while (!nodes.empty())
  {
    auto from {nodes.front()}; nodes.pop_front();
    for (auto const to : graph[from])
    {
      --indegrees[to];
      if (indegrees[to] == 0)
      {
        nodes.emplace_back(to);
      }
      if (lengths[from] + 1 > lengths[to])
      {
        lengths[to] = lengths[from] + 1;
      }
    }
  }
  return *std::max_element(lengths.begin(), lengths.end());
}
