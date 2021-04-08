// alternative 1 provided by TA 鄧晉杰
template <typename H, typename Stack>
int SetStack (H const &h, Stack &stack)
{
  int current_height {0};
  for (auto iterator {h.rbegin()}; iterator != h.rend(); ++iterator)
  {
    stack.push(*iterator);
    current_height += stack.top();
  }
  return current_height;
}

int equalStacks
(
  std::vector<int> h1,
  std::vector<int> h2,
  std::vector<int> h3
)
{
  std::stack<int> stack_1;
  std::stack<int> stack_2;
  std::stack<int> stack_3;
  auto current_height_1 {SetStack(h1, stack_1)};
  auto current_height_2 {SetStack(h2, stack_2)};
  auto current_height_3 {SetStack(h3, stack_3)};
  while
  (
    (current_height_1 != current_height_2)
    ||
    (current_height_2 != current_height_3)
  )
  {
    if
    (
      !stack_1.empty()
      &&
      (current_height_1 >= current_height_2)
      &&
      (current_height_1 >= current_height_3)
    )
    {
      current_height_1 -= stack_1.top();
      stack_1.pop();
    }
    else if
    (
      !stack_2.empty()
      &&
      (current_height_2 >= current_height_1)
      &&
      (current_height_2 >= current_height_3)
    )
    {
      current_height_2 -= stack_2.top();
      stack_2.pop();
    }
    else if (!stack_3.empty())
    {
      current_height_3 -= stack_3.top();
      stack_3.pop();
    }
  }
  return current_height_1;
}

// alternative 2 provided by TA 鄧晉杰
int equalStacks
(
  std::vector<int> h1,
  std::vector<int> h2,
  std::vector<int> h3
)
{
  auto current_height_1 {std::accumulate(h1.begin(), h1.end(), 0)};
  auto current_height_2 {std::accumulate(h2.begin(), h2.end(), 0)};
  auto current_height_3 {std::accumulate(h3.begin(), h3.end(), 0)};
  size_t index_1 {0};
  size_t index_2 {0};
  size_t index_3 {0};
  while
  (
    (current_height_1 != current_height_2)
    ||
    (current_height_2 != current_height_3)
  )
  {
    if
    (
      (index_1 != h1.size())
      &&
      (current_height_1 >= current_height_2)
      &&
      (current_height_1 >= current_height_3)
    )
    {
      current_height_1 -= h1[index_1];
      ++index_1;
    }
    else if
    (
      (index_2 != h2.size())
      &&
      (current_height_2 >= current_height_1)
      &&
      (current_height_2 >= current_height_3)
    )
    {
      current_height_2 -= h2[index_2];
      ++index_2;
    }
    else if (index_3 != h3.size())
    {
      current_height_3 -= h3[index_3];
      ++index_3;
    }
  }
  return current_height_1;
}

// alternative provided by TA 李旺陽
int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    reverse(h1.begin(), h1.end());
    reverse(h2.begin(), h2.end());
    reverse(h3.begin(), h3.end());
    int s1 = accumulate(h1.begin(), h1.end(), 0);
    int s2 = accumulate(h2.begin(), h2.end(), 0);
    int s3 = accumulate(h3.begin(), h3.end(), 0);
    // note std::accumulate = init+a1+a2+a3+...+an

    while ( !(s1==s2&&s1==s3) ) {
        int mx = max({s1, s2, s3});
        if (s1 == mx) {
            s1-=h1.back();
            h1.pop_back();
        }
        if (s2 == mx) {
            s2-=h2.back();
            h2.pop_back();
        }
        if (s3 == mx) {
            s3-=h3.back();
            h3.pop_back();
        }
    }
    return s1;
}
