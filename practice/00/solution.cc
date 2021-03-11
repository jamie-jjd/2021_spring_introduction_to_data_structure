// alternative 1
std::vector<int> reverseArray (std::vector<int> a)
{
  std::reverse(a.begin(), a.end());
  return a;
}

// alternative 2
std::vector<int> reverseArray (std::vector<int> a)
{
  return std::vector<int>(a.rbegin(), a.rend());
}
