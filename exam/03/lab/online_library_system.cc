// alternative provided by TA 鄧晉杰
std::vector<long> Library (long m, std::vector<std::vector<long>> queries)
{
  std::vector<long> responses;
  std::map<long, std::deque<long>> pending_users;
  std::map<long, long> borrowing_books;
  for (auto const &query : queries)
  {
    auto opcode {query[0]};
    if (opcode == 1) // borrow: 1 uid bid
    {
      auto uid {query[1]};
      auto bid {query[2]};
      if (pending_users.find(bid) == pending_users.end())
      {
        pending_users[bid] = std::deque<long>();
      }
      pending_users[bid].push_back(uid);
      if (borrowing_books.find(uid) == borrowing_books.end())
      {
        borrowing_books[uid] = 0;
      }
      ++borrowing_books[uid];
    }
    else if (opcode == 2) // return: 2 bid -1
    {
      auto bid {query[1]};
      auto uid {pending_users[bid].front()};
      pending_users[bid].pop_front();
      --borrowing_books[uid];
    }
    else if (opcode == 3) // book state: 3 bid -1
    {
      auto bid {query[1]};
      if ((pending_users.find(bid) != pending_users.end()) && !pending_users[bid].empty())
      {
        responses.push_back(pending_users[bid].front());
      }
      else
      {
        responses.push_back(0);
      }
    }
    else // user state: 4 uid -1
    {
      auto uid {query[1]};
      if (borrowing_books.find(uid) != borrowing_books.end())
      {
        responses.push_back(borrowing_books[uid]);
      }
      else
      {
        responses.push_back(0);
      }
    }
  }
  return responses;
}
