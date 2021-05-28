// alternative provided by TA 李旺陽
string Travle2(long n, long m, vector<vector<long>> edges) {
    vector<vector<int>> C(n, vector<int>(n));
    for (auto E:edges) {
        C[E[0]][E[1]] = 1;
        C[E[1]][E[0]] = 1;
    }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    bool accept = false;

    do {
        bool connected = true;
        for(int i=0;i<n;++i) {
            if (!C[ord[i]][ord[(i+1)%n]])
                connected = false;
        }
        if (connected) {
            accept = true;
            break;
        }
    } while(next_permutation(ord.begin(), ord.end()));

    return accept ? "yes" : "no" ;
}

// alternative provided by TA 鄧晉杰
template <typename Graph, typename IsVisited>
void DFS
(
  Graph const &graph,
  IsVisited &is_visited,
  long from,
  size_t length,
  bool &is_existed_n_cycle
)
{
  is_visited[from] = true;
  for (auto const to : graph[from])
  {
    if (!is_visited[to])
    {
      DFS(graph, is_visited, to, length + 1, is_existed_n_cycle);
    }
    else if (length == (graph.size() - 1) && to == 0)
    {
      is_existed_n_cycle = true;
    }
  }
  is_visited[from] = false;
  return;
}

std::string Travle2 (long n, long m, std::vector<std::vector<long>> edges)
{
  std::vector<std::vector<long>> graph(n);
  for (auto const &edge : edges)
  {
    graph[edge[0]].emplace_back(edge[1]);
    graph[edge[1]].emplace_back(edge[0]);
  }
  std::vector<bool> is_visited(n);
  bool is_existed_n_cycle {};
  DFS(graph, is_visited, 0, 0, is_existed_n_cycle);
  if (is_existed_n_cycle)
  {
    return "yes";
  }
  return "no";
}
