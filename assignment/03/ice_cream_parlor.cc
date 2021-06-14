// alternative provided by TA 鄧晉杰
std::vector<int> icecreamParlor (int m, std::vector<int> arr)
{
  std::vector<int> index_pair(2);
  std::unordered_map<int, std::vector<int>> map;
  int index {1};
  for (auto const cost : arr)
  {
    if (map.find(cost) != map.end())
    {
      map[cost].emplace_back(index);
    }
    else
    {
      map[cost] = std::vector<int>(1, index);
    }
    ++index;
  }
  for (int cost {1}; cost <= (m / 2); ++cost)
  {
    auto another_cost {m - cost};
    if (cost != another_cost)
    {
      if (map.find(cost) != map.end() && map.find(another_cost) != map.end())
      {
        auto smallest_index_cost {map[cost][0]};
        auto smallest_index_another_cost {map[another_cost][0]};
        index_pair[0] = std::min(smallest_index_cost, smallest_index_another_cost);
        index_pair[1] = std::max(smallest_index_cost, smallest_index_another_cost);
      }
    }
    else
    {
      if (map.find(cost) != map.end() && map[cost].size() > 1)
      {
        index_pair[0] = map[cost][0];
        index_pair[1] = map[cost][1];
      }
    }
  }
  return index_pair;
}

// alternative provided by TA 李旺陽
vector<int> icecreamParlor(int m, vector<int> arr) {
    map<int, vector<int>> mp;
    for(size_t i=0;i<arr.size();++i) {
        mp[arr[i]].emplace_back(i+1);
    }
    for(int i: arr) {
        int j = m - i;
        if(j<=0) continue;
        if(i==j) {
            if (mp[i].size() == 1) continue;
            return mp[i];
        } else if (mp.find(j)!=mp.end()){
            return {mp[i].back(), mp[j].back()};
        }
    }
    __builtin_unreachable();
}
