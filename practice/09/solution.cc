// alternative 1 (shared pointer) provided by TA 鄧晉杰
struct BinarySearchTree
{
  struct Node
  {
    long key;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    Node (long key_): key{key_} {}
  };

  std::shared_ptr<Node> root;

  void Insert (long key)
  {
    if (root == nullptr)
    {
      root = std::make_shared<Node>(key);
    }
    else
    {
      auto node {root};
      while (node != nullptr)
      {
        if (key < node->key)
        {
          if (node->left == nullptr)
          {
            node->left = std::make_shared<Node>(key);
            return;
          }
          node = node->left;
        }
        else if (key > node->key)
        {
          if (node->right == nullptr)
          {
            node->right = std::make_shared<Node>(key);
            return;
          }
          node = node->right;
        }
        else // duplicate key
        {
          return;
        }
      }
    }
    return;
  }

  bool Search (long key)
  {
    auto node {root};
    while (node != nullptr)
    {
      if (key < node->key)
      {
        if (node->left == nullptr)
        {
          return false;
        }
        node = node->left;
      }
      else if (key > node->key)
      {
        if (node->right == nullptr)
        {
          return false;
        }
        node = node->right;
      }
      else
      {
        return true;
      }
    }
    return false;
  }

  long Predecessor (long key)
  {
    --key;
    auto pred {std::make_shared<Node>(0)};
    auto node {root};
    while (node != nullptr)
    {
      if (key < node->key)
      {
        node = node->left;
      }
      else
      {
        pred = node;
        node = node->right;
      }
    }
    return pred->key;
  }

  long Successor (long key)
  {
    ++key;
    auto succ {std::make_shared<Node>(0)};
    auto node {root};
    while (node != nullptr)
    {
      if (key > node->key)
      {
        node = node->right;
      }
      else
      {
        succ = node;
        node = node->left;
      }
    }
    return succ->key;
  }

  long Min ()
  {
    if (root != nullptr)
    {
      auto node {root};
      while (node->left != nullptr)
      {
        node = node->left;
      }
      return node->key;
    }
    return 0;
  }

  long Max ()
  {
    if (root != nullptr)
    {
      auto node {root};
      while (node->right != nullptr)
      {
        node = node->right;
      }
      return node->key;
    }
    return 0;
  }
};

std::vector<long> BinarySearchTreeSimulation(long m, std::vector<std::vector<long>> queries)
{
  std::vector<long> responses;
  BinarySearchTree binary_search_tree;
  for (auto const &query : queries)
  {
    if (query[0] == 1) // insert: 1 key
    {
      binary_search_tree.Insert(query[1]);
    }
    else if (query[0] == 2) // search: 2 key
    {
      responses.emplace_back(binary_search_tree.Search(query[1]));
    }
    else if (query[0] == 3) // predecessor: 3 key
    {
      responses.emplace_back(binary_search_tree.Predecessor(query[1]));
    }
    else if (query[0] == 4) // successor: 4 key
    {
      responses.emplace_back(binary_search_tree.Successor(query[1]));
    }
    else if (query[0] == 5) // min: 5 0
    {
      responses.emplace_back(binary_search_tree.Min());
    }
    else // max: 6 0
    {
      responses.emplace_back(binary_search_tree.Max());
    }
  }
  return responses;
}

// alternative 2 provided by TA 李旺陽
// std::set is usually implemented as balanced binary search tree
vector<long> BinarySearchTreeSimulation(long m, vector<vector<long>> queries) {
    vector<long> res;
    set<long> bst;
    for(vector<long> &op: queries) {
        switch (op[0]) {
            case 1:
                bst.insert(op[1]);
                break;
            case 2:
                res.emplace_back( bst.find(op[1])!=bst.end()?1:0 );
                break;
            case 3: {
                auto ptr = bst.lower_bound(op[1]);
                if (ptr==bst.begin()) res.emplace_back(0);
                else res.emplace_back(*--ptr);
                break;
            }
            case 4: {
                auto ptr = bst.upper_bound(op[1]);
                if (ptr==bst.end()) res.emplace_back(0);
                else res.emplace_back(*ptr);
                break;
            }
            case 5:
                res.emplace_back( bst.empty() ? 0 : *bst.begin() );
                break;
            case 6:
                res.emplace_back( bst.empty() ? 0 : *bst.rbegin() );
                break;

        }
    }
    return res;
}
