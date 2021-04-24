// alternative provided by TA 鄧晉杰
std::vector<long> SimulateBankCounters (long k, std::vector<std::vector<long>> instructions)
{
  std::vector<std::list<long>> counters(k);
  long gid {1};
  for (auto const &instruction : instructions)
  {
    auto tag {instruction[0]};
    if (tag == 1) // guest in: 1 cid -1
    {
      auto const cid {instruction[1]};
      counters[cid].emplace_back(gid);
      ++gid;
    }
    else if (tag == 2) // guest out: 2 cid -1
    {
      auto const cid {instruction[1]};
      counters[cid].pop_front();
    }
    else if (tag == 3) // guest transfer: 3 cid_from cid_to
    {
      auto const cid_from {instruction[1]};
      auto const cid_to {instruction[2]};
      counters[cid_to].merge(counters[cid_from]);
    }
  }
  std::vector<long> smallest_k_gids;
  for (auto const &counter : counters)
  {
    if (!counter.empty())
    {
      smallest_k_gids.emplace_back(counter.front());
    }
    else
    {
      smallest_k_gids.emplace_back(-1);
    }
  }
  return smallest_k_gids;
}

// alternative provided by TA 李旺陽
vector<long> SimulateBankCounters(long k, vector<vector<long>> instructions) {
    vector<long> res(k);
    vector<priority_queue<long, vector<long>, greater<long>>> counter(k);

    int N = 1;
    for(auto op : instructions){
        switch(op[0]){
        case 1:
			counter[op[1]].push(N);
			N++;
			break;
        case 2:
			counter[op[1]].pop();
			break;
        case 3:
			while(!counter[op[1]].empty()){
				counter[op[2]].emplace(counter[op[1]].top());
				counter[op[1]].pop();
			}
			break;
        }
    }

    for(int i=0 ; i<k ; i++){
		if (counter[i].empty())
			res[i] = -1;
		else
			res[i] = counter[i].top();
    }

    return res;
}
