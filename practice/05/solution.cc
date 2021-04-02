// alternative 1 provided by TA 鄧晉杰
std::vector<std::vector<long>> CalculateIndegreesAndOutdegrees (long nodes_size, std::vector<std::vector<long>> edges)
{
  std::vector<std::vector<long>> indegrees_and_outdegrees(2);
  auto &indegrees {indegrees_and_outdegrees[0]};
  auto &outdegrees {indegrees_and_outdegrees[1]};
  indegrees.resize(nodes_size, 0);
  outdegrees.resize(nodes_size, 0);
  for (auto const &edge : edges)
  {
    auto from {edge[0]};
    auto to {edge[1]};
    ++indegrees[to];
    ++outdegrees[from];
  }
  return indegrees_and_outdegrees;
}

// alternative 2 provided by TA 鄧晉杰
std::vector<std::vector<long>> CalculateIndegreesAndOutdegrees (long nodes_size, std::vector<std::vector<long>> edges)
{
  std::vector<std::vector<long>> indegrees_and_outdegrees(2);
  auto &indegrees {indegrees_and_outdegrees[0]};
  auto &outdegrees {indegrees_and_outdegrees[1]};
  std::vector<std::vector<long>> adjacency_lists_from(nodes_size);
  std::vector<std::vector<long>> adjacency_lists_to(nodes_size);
  for (auto const &edge : edges)
  {
    auto const from {edge[0]};
    auto const to {edge[1]};
    adjacency_lists_from[to].emplace_back(from);
    adjacency_lists_to[from].emplace_back(to);
  }
  for (auto const &adjacency_list : adjacency_lists_from)
  {
    indegrees.emplace_back(adjacency_list.size());
  }
  for (auto const &adjacency_list : adjacency_lists_to)
  {
    outdegrees.emplace_back(adjacency_list.size());
  }
  return indegrees_and_outdegrees;
}

// alternative provided by TA 李旺陽
vector<vector<long>> CalculateIndegreesAndOutdegrees(long nodes_size, vector<vector<long>> edges) {
  vector<vector<long>> res(2, vector<long>(nodes_size));
  for (const auto &E : edges) {
    res[0][E[1]]++;
    res[1][E[0]]++;
  }
  return res;
}
