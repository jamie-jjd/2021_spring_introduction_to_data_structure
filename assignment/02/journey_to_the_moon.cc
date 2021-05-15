// alternative (BFS) provided by TA 鄧晉杰
long journeyToMoon (long n, std::vector<std::vector<long>> astronaut)
{
  std::vector<std::vector<long>> graph(n);
  for (auto pair : astronaut)
  {
    graph[pair[0]].emplace_back(pair[1]);
    graph[pair[1]].emplace_back(pair[0]);
  }
  std::vector<bool> is_discovered(n);
  long amount_valid_pairs {};
  long country_size_sum {};
  for (long id {}; id != n; ++id)
  {
    if (!is_discovered[id])
    {
      long country_size {};
      std::deque<long> astronauts;
      is_discovered[id] = true;
      astronauts.emplace_back(id);
      while (!astronauts.empty())
      {
        ++country_size;
        auto u {astronauts.front()};
        astronauts.pop_front();
        for (auto v : graph[u])
        {
          if (!is_discovered[v])
          {
            is_discovered[v] = true;
            astronauts.emplace_back(v);
          }
        }
      }
      amount_valid_pairs += (country_size_sum * country_size);
      country_size_sum += country_size;
    }
  }
  return amount_valid_pairs;
}
