# alternative provided by TA 李旺陽
def icecreamParlor(m, arr):
    mp = dict()
    for i in range(len(arr)):
        if arr[i] not in mp:
            mp[arr[i]] = []
        mp[arr[i]].append(i+1)
    for i in arr:
        j = m - i
        if j<0:
            continue
        if i==j:
            if len(mp[i]) == 1:
                continue
            return mp[i]
        elif j in mp:
            return [mp[i][0], mp[j][0]]
