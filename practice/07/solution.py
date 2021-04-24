# alternative (recursive DFS) provided by TA 李旺陽
def preOrder(root):
    if root == None:
        return
    print(root.info, end=' ')
    preOrder(root.left)
    preOrder(root.right)

# alternative (recursive DFS) provided by TA 李旺陽
def inOrder(root):
    if root == None:
        return
    inOrder(root.left)
    print(root.info, end=' ')
    inOrder(root.right)

# alternative (recursive DFS) provided by TA 李旺陽
def postOrder(root):
    if root == None:
        return
    postOrder(root.left)
    postOrder(root.right)
    print(root.info, end=' ')

# alternative (BFS) provided by TA 李旺陽
from collections import deque
def levelOrder(root):
    dq = deque()
    dq.append(root)
    while len(dq) > 0:
        head = dq.popleft()
        print(head.info, end=' ')
        if head.left != None:
            dq.append(head.left)
        if head.right != None:
            dq.append(head.right)
