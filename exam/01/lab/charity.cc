// alternative 1 provided by TA 鄧晉杰
long LaunchDonations (std::vector<long> savings, std::vector<long> moneys)
{
  auto compare {std::greater<long>{}};
  std::make_heap(savings.begin(), savings.end(), compare);
  for (auto const &money : moneys)
  {
    auto the_lowerest_savings {savings.front()};
    std::pop_heap(savings.begin(), savings.end(), compare);
    savings.pop_back();
    savings.emplace_back(the_lowerest_savings + money);
    std::push_heap(savings.begin(), savings.end(), compare);
  }
  std::sort_heap(savings.begin(), savings.end(), compare);
  return savings.front();
}

// alternative 2 provided by TA 鄧晉杰
long LaunchDonations (std::vector<long> savings, std::vector<long> moneys)
{
  std::priority_queue<long, std::vector<long>, std::greater<long>> min_heap(savings.begin(), savings.end());
  for (auto const &money : moneys)
  {
    auto the_lowerest_savings {min_heap.top()};
    min_heap.pop();
    min_heap.push(the_lowerest_savings + money);
  }
  while (min_heap.size() != 1)
  {
    min_heap.pop();
  }
  return min_heap.top();
}

// alternative provided by TA 李旺陽
long LaunchDonations(vector<long> savings, vector<long> moneys) {
    priority_queue<long,vector<long>,greater<long>> pq;
    for (auto v : savings)
        pq.push(v);

    for (auto m : moneys) {
        long t = pq.top();
        pq.pop();
        t += m;
        pq.emplace(t);
    }

    while(pq.size() > 1)
        pq.pop();

    return pq.top();
}
