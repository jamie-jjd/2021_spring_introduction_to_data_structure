std::vector<string> Search (std::vector<long> A, std::vector<long> Q)
{
  std::vector<string> R(Q.size());
  std::sort(A.begin(), A.end());
  for (auto const &q : Q)
  {
    if (std::binary_search(A.begin(), A.end(), q))
    {
      R.emplace_back("yes");
    }
    else
    {
      R.emplace_back("no");
    }
  }
  return R;
}
