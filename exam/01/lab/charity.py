# alternative provided by TA 李旺陽
import heapq
def LaunchDonations(savings, moneys):
    heapq.heapify(savings)
    for m in moneys:
        x = heapq.heappop(savings)
        heapq.heappush(savings, x+m)
    return sorted(savings)[-1]
