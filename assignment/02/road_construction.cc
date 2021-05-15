// alternative (BFS) provided by TA 鄧晉杰
template
<
  typename Graph,
  typename IsDiscovered,
  typename Costs
>
void CalculateNextIslandCost
(
  Graph const &graph,
  IsDiscovered &is_discovered,
  Costs &costs,
  long source
)
{
  costs.emplace_back(0);
  std::deque<long> nodes;
  is_discovered[source] = true;
  nodes.emplace_back(source);
  while (!nodes.empty())
  {
    auto from {nodes.front()};
    nodes.pop_front();
    for (auto to_cost : graph[from])
    {
      auto to {std::get<0>(to_cost)};
      auto cost {std::get<1>(to_cost)};
      if (!is_discovered[to])
      {
        is_discovered[to] = true;
        nodes.emplace_back(to);
      }
      costs.back() += cost;
    }
  }
  costs.back() /= 2; // hand-shaking theorem
  return;
}

std::vector<long> CalculateCosts (long n, long m, std::vector<std::vector<long>> roads)
{
  std::vector<long> costs;
  std::vector<std::vector<std::pair<long, long>>> graph(n);
  for (auto road : roads)
  {
    graph[road[0]].emplace_back(road[1], road[2]);
    graph[road[1]].emplace_back(road[0], road[2]);
  }
  std::vector<bool> is_discovered(n);
  for (long source {}; source != n; ++source)
  {
    if (!is_discovered[source])
    {
      CalculateNextIslandCost(graph, is_discovered, costs, source);
    }
  }
  std::sort(costs.begin(), costs.end());
  return costs;
}
