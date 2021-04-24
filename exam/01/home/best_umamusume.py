# alternative provided by TA 李旺陽
def WinScore(HaruUraraAbility, TokaiTeioAbility):
    # Write your code here
    HaruUraraAbility.sort()
    TokaiTeioAbility.sort(reverse = True)

    ans = 0
    for e in HaruUraraAbility:
        while len(TokaiTeioAbility) !=0 and TokaiTeioAbility[-1] < e:
            TokaiTeioAbility.pop()
        ans += len(HaruUraraAbility) - len(TokaiTeioAbility)

    return ans
