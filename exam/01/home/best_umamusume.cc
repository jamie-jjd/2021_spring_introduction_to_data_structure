// alternative provided by TA 李旺陽
long WinScore(vector<long> HaruUraraAbility, vector<long> TokaiTeioAbility) {
    sort(HaruUraraAbility.begin(), HaruUraraAbility.end());
    sort(TokaiTeioAbility.begin(), TokaiTeioAbility.end(), greater<long>());

    long ans = 0;

    for (long e : HaruUraraAbility) {
        while (TokaiTeioAbility.size() && TokaiTeioAbility.back() < e )
            TokaiTeioAbility.pop_back();
        ans += HaruUraraAbility.size() - TokaiTeioAbility.size();
    }

    return ans;
}

// alternative provided by TA 鄧晉杰
long WinScore (std::vector<long> HaruUraraAbility, std::vector<long> TokaiTeioAbility)
{
  long win_score {};
  auto compare {std::greater<long>{}};
  std::sort(HaruUraraAbility.begin(), HaruUraraAbility.end());
  std::sort(TokaiTeioAbility.begin(), TokaiTeioAbility.end());
  auto haru_iterator {HaruUraraAbility.begin()};
  auto tokai_iterator {TokaiTeioAbility.begin()};
  while
  (
    (haru_iterator != HaruUraraAbility.end())
    &&
    (tokai_iterator != TokaiTeioAbility.end())
  )
  {
    if (*haru_iterator <= *tokai_iterator)
    {
      win_score += std::distance(TokaiTeioAbility.begin(), tokai_iterator);
      ++haru_iterator;
    }
    else
    {
      ++tokai_iterator;
    }
  }
  win_score += std::distance(haru_iterator, HaruUraraAbility.end()) * TokaiTeioAbility.size();
  return win_score;
}
