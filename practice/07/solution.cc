// alternative (recursive DFS) provided by TA 鄧晉杰
void preOrder (Node *root)
{
  if (root != nullptr)
  {
    std::cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
  }
  return;
}

// alternative (recursive DFS) provided by TA 李旺陽
void preOrder(Node *root) {
	if (!root) return;
	std::cout << root->data << ' ';
	preOrder(root->left);
	preOrder(root->right);
}

// alternative (recursive DFS) provided by TA 鄧晉杰
void inOrder (Node *root)
{
  if (root != nullptr)
  {
    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
  }
  return;
}

// alternative (recursive DFS) provided by TA 李旺陽
void inOrder(Node *root) {
	if (!root) return;
	inOrder(root->left);
	std::cout << root->data << ' ';
	inOrder(root->right);
}

// alternative (recursive DFS) provided by TA 鄧晉杰
void postOrder (Node *root)
{
  if (root != nullptr)
  {
    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->data << " ";
  }
  return;
}

// alternative (recursive DFS) provided by TA 李旺陽
void postOrder(Node *root) {
	if (!root) return;
	postOrder(root->left);
	postOrder(root->right);
	std::cout << root->data << ' ';
}

// alternative (BFS) provided by TA 鄧晉杰
void levelOrder (Node *root)
{
  if (root != nullptr)
  {
    std::deque<Node*> nodes;
    nodes.emplace_back(root);
    while (!nodes.empty())
    {
      Node *node {nodes.front()};
      std::cout << node->data << " ";
      nodes.pop_front();
      if (node->left != nullptr)
      {
        nodes.emplace_back(node->left);
      }
      if (node->right != nullptr)
      {
        nodes.emplace_back(node->right);
      }
    }
  }
  return;
}

// alternative (BFS) provided by TA 李旺陽
void levelOrder(Node * root) {
    queue<Node *> qu;
    qu.emplace(root);

    while (!qu.empty()) {
        Node *ptr = qu.front();
        qu.pop();

        if (!ptr) continue;
        cout<<ptr->data<<' ';
        if (ptr->left) qu.emplace(ptr->left);
        if (ptr->right) qu.emplace(ptr->right);
    }
}
