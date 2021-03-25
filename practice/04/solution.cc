// provided by TA 鄧晉杰
std::vector<long> PerformOperationsOnLists (std::vector<std::vector<long>> operations)
{
  std::vector<std::list<long>> L(2);
  for (auto const &op : operations)
  {
    auto op_code {op[0]};
    if (op_code == 0) // insert: 1 id pos val
    {
      auto id {op[1]};
      auto pos {op[2]};
      auto val {op[3]};
      if (pos == 0)
      {
        // equivalent to L[id].insert(L.begin(), val)
        L[id].push_front(val);
      }
      else if (pos == static_cast<long>(L[id].size()))
      {
        // equivalent to L[id].insert(L.end(), val)
        L[id].push_back(val);
      }
      else
      {
        L[id].insert(std::next(L[id].begin(), pos), val);
      }
    }
    else if (op_code == 1) // delete: 2 id pos
    {
      auto id {op[1]};
      auto pos {op[2]};
      if (pos == 0)
      {
        // equivalent to L[id].erase(L.begin())
        L[id].pop_front();
      }
      else if (pos == static_cast<long>(L[id].size() - 1))
      {
        // equivalent to L[id].erase(std::prev(L.end()))
        L[id].pop_back();
      }
      else
      {
        L[id].erase(std::next(L[id].begin(), pos));
      }
    }
    else // transfer: 3 id_to pos_to id_from pos_from
    {
      auto id_to {op[1]};
      auto pos_to {op[2]};
      auto id_from {op[3]};
      auto pos_from {op[4]};
      L[id_to].splice
      (
        std::next(L[id_to].begin(), pos_to),
        L[id_from],
        std::next(L[id_from].begin(), pos_from)
      );
    }
  }
  L[0].splice(L[0].end(), L[1]);
  return std::vector<long>(L[0].begin(), L[0].end());
}

// provided by TA 李旺陽
vector<long> PerformOperationsOnLists(vector<vector<long>> operations) {
    std::list<long> L[2];
    for(auto &Action : operations) {
        switch (Action[0]) {
            case 0: { // Insert
                long id  = Action[1];
                long pos = Action[2];
                long val = Action[3];

                auto ptr = L[id].begin();
                std::advance(ptr, pos);
                L[id].insert(ptr, val);
                break;
            }
            case 1: { // Delete
                long id  = Action[1];
                long pos = Action[2];

                auto ptr = L[id].begin();
                std::advance(ptr, pos);
                L[id].erase(ptr);
                break;
            }
            case 2: { // Trans
                long idTo  = Action[1];
                long posTo = Action[2];
                long idFrom = Action[3];
                long PosFrom = Action[4];

                auto ptrFrom = L[idFrom].begin();
                std::advance(ptrFrom, PosFrom);

                auto ptrTo = L[idTo].begin();
                std::advance(ptrTo, posTo);
                L[idTo].splice(ptrTo, L[idFrom], ptrFrom, L[idFrom].end());
                break;
            }
            default:
                __builtin_unreachable();
        }
    }

    vector<long> res;
    for(auto e:L[0]) res.emplace_back(e);
    for(auto e:L[1]) res.emplace_back(e);
    return res;
}
