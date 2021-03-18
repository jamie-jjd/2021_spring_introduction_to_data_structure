// alternative 1
template <typename Iterator, typename Compare>
void MyHeapSort (Iterator begin, Iterator end, Compare compare)
{
  if (!std::is_heap(begin, end, compare))
  {
    /* make_heap */
    for (auto last_iterator {std::next(begin)}; last_iterator != end; ++last_iterator)
    {
      std::push_heap(begin, last_iterator, compare);
    }
  }
  /* sort_heap */
  for (auto last_iterator {end}; last_iterator != begin; --last_iterator)
  {
    std::pop_heap(begin, last_iterator, compare);
  }
  return;
}

std::vector<long> HeapSortInNondecreasingOrder (std::vector<long> A)
{
  MyHeapSort(A.begin(), A.end(), std::less<long>{});
  return A;
}

std::vector<long> HeapSortInNonincreasingOrder (std::vector<long> A)
{
  MyHeapSort(A.begin(), A.end(), std::greater<long>{});
  return A;
}

// alternative 2
template <typename Iterator, typename Compare>
void MyHeapSort (Iterator begin, Iterator end, Compare compare)
{
  if (!std::is_heap(begin, end, compare))
  {
    std::make_heap(begin, end, compare);
  }
  std::sort_heap(begin, end, compare);
  return;
}

std::vector<long> HeapSortInNondecreasingOrder (std::vector<long> A)
{
  MyHeapSort(A.begin(), A.end(), std::less<long>{});
  return A;
}

std::vector<long> HeapSortInNonincreasingOrder(std::vector<long> A)
{
  MyHeapSort(A.begin(), A.end(), std::greater<long>{});
  return A;
}

// alternative 3
template <typename Iterator, typename Compare>
void MyHeapSort (Iterator begin, Iterator end, Compare compare)
{
  priority_queue<long, std::vector<long>, Compare> heap;
  for (auto iterator {begin}; iterator != end; ++iterator)
  {
    heap.push(*iterator);
  }
  for (auto iterator {begin}; iterator != end; ++iterator)
  {
    *iterator = heap.top();
    heap.pop();
  }
  return;
}

std::vector<long> HeapSortInNondecreasingOrder (std::vector<long> A)
{
  MyHeapSort(A.begin(), A.end(), std::greater<long>{});
  return A;
}

std::vector<long> HeapSortInNonincreasingOrder(std::vector<long> A)
{
  MyHeapSort(A.begin(), A.end(), std::less<long>{});
  return A;
}
