// alternative provided by TA 鄧晉杰
std::vector<long> Simulate (long m, std::vector<std::vector<long>> queries)
{
  std::vector<long> responses;
  /*
  *  std::set is usually implemented as balanced binary search tree (espcially red-black tree)
  *  we can also use std::unordered_set, which is usually implemented as hash table
  */
  std::set<long> set;
  for (auto query : queries)
  {
    auto type {query[0]};
    auto key {query[1]};
    if (type == 1) // insert: 1 key
    {
      set.insert(key);
    }
    else if (type == 2) // delete: 2 key
    {
      set.erase(key);
    }
    else // search: 3 key
    {
      responses.emplace_back(set.count(key));
    }
  }
  return responses;
}

// alternative provided by TA 李旺陽
std::vector<long> Simulate (long m, std::vector<std::vector<long>> queries)
{
    set<long> st;
    vector<long> res;
    for(auto &op: queries) {
        switch(op[0]) {
            case 1:
                st.insert(op[1]);
                break;
            case 2:
                st.erase(op[1]);
                break;
            case 3:
                res.emplace_back(st.find(op[1])!=st.end());
                break;
        }
    }
    return res;
}
