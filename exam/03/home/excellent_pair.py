# alternative provided by TA 鄧晉杰
def ExcellentPair (n, Nums):
    filtered_nums = []
    for num in Nums:
        is_not_filtered = True
        if num <= 77777777:
            num_ = num
            while num_ != 0:
                if num_ % 10 > 7:
                    is_not_filtered = False
                    break
                num_ //= 10
        else:
            is_not_filtered = False
        if is_not_filtered:
            filtered_nums.append(num)
    filtered_nums.sort()
    amount = 0
    i = 0
    j = len(filtered_nums) - 1
    while i < j:
        sum = filtered_nums[i] + filtered_nums[j]
        if sum == 77777777:
            amount += 2
            i += 1
        elif sum < 77777777:
            i += 1
        else:
            j -= 1
    return amount
