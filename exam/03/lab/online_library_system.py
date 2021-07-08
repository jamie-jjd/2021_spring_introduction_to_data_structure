# alternative provided by TA 鄧晉杰
from collections import deque
def Library (m, queries):
    responses = []
    pending_users = {}
    borrowing_books = {}
    for query in queries:
        opcode = query[0]
        if opcode == 1:
            uid = query[1]
            bid = query[2]
            if bid not in pending_users:
                pending_users[bid] = deque()
            pending_users[bid].append(uid)
            if uid not in borrowing_books:
                borrowing_books[uid] = 0
            borrowing_books[uid] += 1
        elif opcode == 2:
            bid = query[1]
            uid = pending_users[bid][0]
            pending_users[bid].popleft()
            borrowing_books[uid] -= 1
        elif opcode == 3:
            bid = query[1]
            if bid in pending_users and len(pending_users) != 0:
                responses.append(pending_users[bid][0])
            else:
                responses.append(0)
        else:
            uid = query[1]
            if uid in borrowing_books:
                responses.append(borrowing_books[uid])
            else:
                responses.append(0)
    return responses
