std::vector<string> Search (std::vector<long> A, std::vector<long> Q)
{
  std::vector<string> R;
  std::sort(A.begin(), A.end());
  for (auto const &q : Q)
  {
    if (std::binary_search(A.begin(), A.end(), q))
    {
      R.push_back("yes");
    }
    else
    {
      R.push_back("no");
    }
  }
  return R;
}
