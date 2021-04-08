// alternative 1 provided by TA 鄧晉杰
std::vector<long> MergeKSortedSequences (std::vector<std::vector<long>> sequences)
{
  std::list<long> merged_sequences;
  for (auto const &sequence : sequences)
  {
    merged_sequences.merge(std::list<long>(sequence.begin(), sequence.end()), std::greater<long>{});
  }
  return std::vector<long>(merged_sequences.begin(), merged_sequences.end());
}

// alternative 2 provided by TA 鄧晉杰
std::vector<long> MergeKSortedSequences (std::vector<std::vector<long>> sequences)
{
  std::vector<long> merged_sequences;
  for (auto const &sequence : sequences)
  {
    for (auto const &element : sequence)
    {
      merged_sequences.emplace_back(element);
    }
  }
  std::make_heap(merged_sequences.begin(), merged_sequences.end(), std::greater<long>{});
  std::sort_heap(merged_sequences.begin(), merged_sequences.end(), std::greater<long>{});
  return merged_sequences;
}

// alternative 3 provided by TA 鄧晉杰
std::vector<long> MergeKSortedSequences (std::vector<std::vector<long>> sequences)
{
  std::vector<std::list<long>> lists;
  for (auto const &sequence : sequences)
  {
    lists.emplace_back(std::list<long>(sequence.begin(), sequence.end()));
  }
  using MyTuple = std::tuple<size_t, size_t>;
  auto compare
  {
    [] (MyTuple const &left, MyTuple const &right)
    {
      return (std::get<1>(left) > std::get<1>(right));
    }
  };
  std::vector<MyTuple> min_heap;
  for (size_t index {}; index != lists.size(); ++index)
  {
    min_heap.emplace_back(index, lists[index].size());
    std::push_heap(min_heap.begin(), min_heap.end(), compare);
  }
  while (min_heap.size() != 1)
  {
    auto left_index {std::get<0>(min_heap.front())};
    std::pop_heap(min_heap.begin(), min_heap.end(), compare);
    min_heap.pop_back();
    auto right_index {std::get<0>(min_heap.front())};
    std::pop_heap(min_heap.begin(), min_heap.end(), compare);
    min_heap.pop_back();
    lists[left_index].merge(lists[right_index], std::greater<long>{});
    min_heap.emplace_back(left_index, lists[left_index].size());
    std::push_heap(min_heap.begin(), min_heap.end(), compare);
  }
  auto &merged_lists {lists[std::get<0>(min_heap.front())]};
  return std::vector<long>(merged_lists.begin(), merged_lists.end());
}

// alternative provided by TA 李旺陽
vector<long> MergeKSortedSequences(vector<vector<long>> sequences) {
    vector<long> res;

    auto empty = [&]() {
        for(const auto &seq: sequences)
            if (seq.size() != 0)
                return false;
        return true;
    };

    auto findMin = [&]()->long {
        long mn = LONG_MAX;
        for(const auto &seq: sequences)
            if (!seq.empty() && seq.back() < mn)
                mn = seq.back();
        return mn;
    };

    auto pop = [&](long t) {
        for(auto &seq: sequences)
            if (!seq.empty() && seq.back() == t) {
                seq.pop_back();
                return ;
            }
    };

    while (!empty()) {
        res.push_back(findMin());
        pop(res.back());

    }
    reverse(res.begin(), res.end());
    return res;
}
