// alternative 1
vector<int> reverseArray(vector<int> a)
{
  reverse(a.begin(), a.end());
  return a;
}

// alternative 2
vector<int> reverseArray(vector<int> a)
{
  return vector<int>(a.rbegin(), a.rend());
}
