// alternative 1 provided by TA 鄧晉杰
std::vector<int> getMax (std::vector<std::string> operations)
{
  std::vector<int> maxs;
  std::stack<int> stack;
  std::stack<int> max_stack;
  for (auto const &operation : operations)
  {
    std::stringstream tokens {operation};
    int type {};
    tokens >> type;
    if (type == 1) // push x
    {
      int x {};
      tokens >> x;
      if (max_stack.empty() || (max_stack.top() <= x))
      {
        max_stack.push(x);
      }
      stack.push(x);
    }
    else if (type == 2) // delete top
    {
      if (max_stack.top() == stack.top())
      {
        max_stack.pop();
      }
      stack.pop();
    }
    else // print max
    {
      maxs.emplace_back(max_stack.top());
    }
  }
  return maxs;
}

// alternative 2 provided by TA 鄧晉杰
std::vector<int> getMax (std::vector<std::string> operations)
{
  std::vector<int> maxs;
  int current_max {0};
  std::stack<int> stack;
  for (auto const &operation : operations)
  {
    std::stringstream tokens {operation};
    int type {};
    tokens >> type;
    if (type == 1) // push x
    {
      int x {};
      tokens >> x;
      if (current_max <= x)
      {
        stack.push(current_max);
        current_max = x;
      }
      else
      {
        stack.push(x - current_max);
      }
    }
    else if (type == 2) // delete top
    {
      if (stack.top() >= 0)
      {
        current_max = stack.top();
      }
      stack.pop();
    }
    else // print max
    {
      maxs.emplace_back(current_max);
    }
  }
  return maxs;
}

// alternative provided by TA 李旺陽
vector<int> getMax(vector<string> operations) {
    vector<int> ans;
    stack<int> st;
    st.push(INT_MIN);

    for(auto op:operations) {
        if (op[0] == '1') {
            int num = stoi(op.data() + 1); // op[1:]
            st.push(max(st.top(), num));
        } else if (op[0] == '2') {
            st.pop();
        } else {
            ans.push_back(st.top());
        }
    }
    return ans;
}
