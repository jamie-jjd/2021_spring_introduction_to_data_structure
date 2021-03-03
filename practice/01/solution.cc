vector<string> Search (vector<long> A, vector<long> Q)
{
  vector<string> R;
  sort(A.begin(), A.end());
  for (auto const &q : Q)
  {
    if (binary_search(A.begin(), A.end(), q))
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
