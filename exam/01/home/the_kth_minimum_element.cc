// alternative provided by TA 李旺陽
vector<long> KthElements(long k, long n, vector<long> a) {
    priority_queue<long> pq;
    vector<long> ans;

    for(long i=0; i < n; ++i) {
        if (i < k) {
            pq.push(a[i]);
            if ((long)pq.size() == k) {
                ans.emplace_back(pq.top());
            }
        } else {
            if (a[i] < pq.top()) {
                pq.push(a[i]);
                pq.pop();
            }
            ans.emplace_back(pq.top());
        }
    }
    return ans;
}

// alternative 1 provided by TA 鄧晉杰
std::vector<long> KthElements (long k, long n, std::vector<long> a)
{
  std::vector<long> kth_elements;
  auto kth_iterator {std::next(a.begin(), k)};
  std::vector<long> max_heap(a.begin(), kth_iterator);
  std::make_heap(max_heap.begin(), max_heap.end());
  kth_elements.emplace_back(max_heap.front());
  for (auto iterator {kth_iterator}; iterator != a.end(); ++iterator)
  {
    if (*iterator < max_heap.front())
    {
      std::pop_heap(max_heap.begin(), max_heap.end());
      max_heap.back() = *iterator;
      std::push_heap(max_heap.begin(), max_heap.end());
    }
    kth_elements.emplace_back(max_heap.front());
  }
  return kth_elements;
}

// alternative 2 provided by TA 鄧晉杰
std::vector<long> KthElements (long k, long n, std::vector<long> a)
{
  std::vector<long> kth_elements;
  auto kth_iterator {std::next(a.begin(), k)};
  std::priority_queue<long> max_heap(a.begin(), kth_iterator);
  kth_elements.emplace_back(max_heap.top());
  for (auto iterator {kth_iterator}; iterator != a.end(); ++iterator)
  {
    if (*iterator < max_heap.top())
    {
      max_heap.pop();
      max_heap.push(*iterator);
    }
    kth_elements.emplace_back(max_heap.top());
  }
  return kth_elements;
}
