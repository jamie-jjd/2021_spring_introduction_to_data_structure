// alternative 1 (topological order using queue) provided by TA 鄧晉杰
std::string CheckGraph (long n, long m, vector<vector<long>> edges)
{
  std::vector<std::vector<long>> graph(n);
  std::vector<long> indegrees(n);
  for (auto edge : edges)
  {
    graph[edge[0]].emplace_back(edge[1]);
    ++indegrees[edge[1]];
  }
  std::deque<long> nodes;
  for (long source {}; source != n; ++source)
  {
    if (indegrees[source] == 0)
    {
      nodes.emplace_back(source);
    }
  }
  while (!nodes.empty())
  {
    auto from {nodes.front()};
    nodes.pop_front();
    for (auto to : graph[from])
    {
      --indegrees[to];
      if (indegrees[to] == 0)
      {
        nodes.emplace_back(to);
      }
    }
  }
  for (auto indegree : indegrees)
  {
    if (indegree != 0)
    {
      return "no";
    }
  }
  return "yes";
}

// alternative 2 (topological order by DFS) provided by TA 鄧晉杰
template <typename Graph, typename IsVisisted, typename FinishTime>
void DFS
(
  Graph const &graph,
  IsVisisted &is_visited,
  FinishTime &finish_time,
  long &time,
  long from
)
{
  is_visited[from] = true;
  for (auto to : graph[from])
  {
    if (!is_visited[to])
    {
      DFS(graph, is_visited, finish_time, time, to);
    }
  }
  finish_time[from] = time++;
  return;
}

std::string CheckGraph (long n, long m, vector<vector<long>> edges)
{
  std::vector<std::vector<long>> graph(n);
  for (auto edge : edges)
  {
    graph[edge[0]].emplace_back(edge[1]);
  }
  std::vector<bool> is_visited(n);
  std::vector<long> finish_time(n);
  long time {};
  for (long from {}; from != n; ++from)
  {
    if (!is_visited[from])
    {
      DFS(graph, is_visited, finish_time, time, from);
    }
  }
  for (long from {}; from != n; ++from)
  {
    for (auto to : graph[from])
    {
      if (finish_time[from] < finish_time[to])
      {
        return "no";
      }
    }
  }
  return "yes";
}

// alternative provided by TA 李旺陽
string CheckGraph(long n, long m, vector<vector<long>> edges) {
    vector<int> indeg(n);
    vector<vector<int>> E(n);
    stack<int> st;

    for(auto v:edges) {
        E[v[0]].emplace_back(v[1]);
        indeg[v[1]]++;
    }

    for(int i=0;i<n;++i)
        if (indeg[i] == 0)
            st.emplace(i);

    int cnt = 0;

    while (!st.empty()) {
        int s = st.top();
        st.pop();

        cnt++;

        for(int e:E[s]) {
            indeg[e]--;
            if (indeg[e] == 0)
                st.emplace(e);
        }
    }

    return cnt == n ? "yes" : "no";
}
