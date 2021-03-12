template <typename Iterator, typename Compare>
void MyMergeSort (Iterator begin, Iterator end, Iterator buffer_begin, Iterator buffer_end, Compare compare)
{
  auto size {std::distance(begin, end)};
  auto middle {std::next(begin, size / 2)};
  auto buffer_middle {std::next(buffer_begin, size / 2)};
  if (begin != middle)
  {
    MyMergeSort(begin, middle, buffer_begin, buffer_middle, compare);
    MyMergeSort(middle, end, buffer_middle, buffer_end, compare);
    std::merge(begin, middle, middle, end, buffer_begin, compare);
    std::copy(buffer_begin, buffer_end, begin);
  }
  return;
}

std::vector<long> MergeSortInNondecreasingOrder (std::vector<long> A)
{
  std::vector<long> buffer(A.size());
  MyMergeSort(A.begin(), A.end(), buffer.begin(), buffer.end(), std::less<long>{});
  return A;
}

std::vector<long> MergeSortInNonincreasingOrder (std::vector<long> A)
{
  std::vector<long> buffer(A.size());
  MyMergeSort(A.begin(), A.end(), buffer.begin(), buffer.end(), std::greater<long>{});
  return A;
}
