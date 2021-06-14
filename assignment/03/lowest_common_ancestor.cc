// alternative provided by TA 鄧晉杰
Node* lca (Node *root, int v1, int v2)
{
  if (root != nullptr)
  {
    if (root->data == v1 || root->data == v2)
    {
      return root;
    }
    else
    {
      Node *left {lca(root->left, v1, v2)};
      Node *right {lca(root->right, v1, v2)};
      if (left != nullptr && right != nullptr)
      {
        return root;
      }
      else if (left != nullptr)
      {
        return left;
      }
      else if (right != nullptr)
      {
        return right;
      }
    }
  }
  return nullptr;
}

// alternative provided by TA 李旺陽
vector<Node*> path(Node *root, int v) {
    vector<Node*> path;
    while(root != nullptr) {
        path.push_back(root);
        if (v == root->data)
            break;
        if (v < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return path;
}

Node *lca(Node *root, int v1,int v2) {
    auto p1 = path(root, v1);
    auto p2 = path(root, v2);
    int len = min(p1.size(), p2.size());
    int ind = 0;
    while (ind < len && p1[ind] == p2[ind] )
        ind++;
    return p1[ind-1];
}
