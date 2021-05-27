// alternative provided by TA 鄧晉杰
std::vector<long> Simulate (long m, std::vector<std::vector<long>> queries)
{
  std::vector<long> responses;
  std::map<long, long> map;
  for (auto const &query : queries)
  {
    if (query[0] == 1) // insert: 1 key value
    {
      map[query[1]] = query[2];
    }
    else if (query[0] == 2) // delete: 2 key -1
    {
      map.erase(query[1]);
    }
    else // search: 3 key -1
    {
      if (map.find(query[1]) != map.end())
      {
        responses.emplace_back(map[query[1]]);
      }
      else
      {
        responses.emplace_back(0);
      }
    }
  }
  return responses;
}

// alternative provided by TA 李旺陽
vector<long> Simulate(long m, vector<vector<long>> queries) {
    unordered_map<long, long> ump;
    vector<long> res;

    for(auto op: queries) {
        if (op[0] == 1) {
            ump[op[1]] = op[2];
        } else if (op[0] == 2) {
            ump.erase(op[1]);
        } else {
            // note, it key not in map/unordered_map, the value is 0
            // however, it will create a key-pair (key, 0)
            res.emplace_back(ump[op[1]]);
        }
    }
    return res;
}
