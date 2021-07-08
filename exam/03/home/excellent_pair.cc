// alternative provided by TA 鄧晉杰
long ExcellentPair (long n, std::vector<long> Nums)
{
  long amount_pairs {};
  Nums.erase
  (
    std::remove_if
    (
      Nums.begin(),
      Nums.end(),
      [] (long number)
      {
        if (number > 77'777'777)
        {
          return true;
        }
        while (number != 0)
        {
          if (number % 10 > 7)
          {
            return true;
          }
          number /= 10;
        }
        return false;
      }
    ),
    Nums.end()
  );
  std::sort(Nums.begin(), Nums.end());
  auto it {Nums.begin()};
  auto rit {std::prev(Nums.end())};
  while (it != rit)
  {
    auto sum {*it + *rit};
    if (sum == 77'777'777)
    {
      amount_pairs += 2;
      ++it;
    }
    else if (sum < 77'777'777)
    {
      ++it;
    }
    else
    {
      --rit;
    }
  }
  return amount_pairs;
}
