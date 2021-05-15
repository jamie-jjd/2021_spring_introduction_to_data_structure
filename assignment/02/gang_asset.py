# alternative provided by TA 蔡宗霖
def count(root_id, adj_l, assets):
    for child in adj_l[root_id]:
            assets[root_id] = assets[root_id] + count(child, adj_l, assets)
    return(assets[root_id])

def CalculateGangAsset(n, root_id, edges, assets):
    adj_l = [[] for _ in range(n)]
    for s, t in edges:
        adj_l[s].append(t)

    count(root_id, adj_l, assets)
    return(max(assets))
