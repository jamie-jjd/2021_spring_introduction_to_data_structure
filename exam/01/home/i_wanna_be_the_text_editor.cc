// alternative provided by TA 李旺陽
string TextEditor(string KeyboardInputs)
{
    string head, tail;
    bool insert = true;

    for (char c : KeyboardInputs)
    {
        switch (c)
        {
        case '<':
            if (!head.empty()) {
                tail.push_back(head.back());
                head.pop_back();
            }
            break;
        case '>':
            if (!tail.empty()) {
                head.push_back(tail.back());
                tail.pop_back();
            }
            break;
        case '@': // Back
            if (!head.empty()) {
                head.pop_back();
            }
            break;
        case '$': // switch insert mod
            insert = !insert;
            break;
        default:
            assert(isalnum(c));
            head.push_back(c);
            if (!insert && tail.size())
                tail.pop_back();
        }
    }

    reverse(tail.begin(), tail.end());
    return head + tail;
}

// alternative provided by TA 鄧晉杰
std::string TextEditor (std::string KeyboardInputs)
{
  std::list<char> text;
  auto cursor_position {text.end()};
  bool is_insertion_mode {true};
  for (auto const &character : KeyboardInputs)
  {
    if (std::isalpha(character))
    {
      if (is_insertion_mode || cursor_position == text.end())
      {
        text.insert(cursor_position, character);
      }
      else
      {
        *cursor_position = character;
        std::advance(cursor_position, 1);
      }
    }
    else if (character == '<')
    {
      if (cursor_position != text.begin())
      {
        std::advance(cursor_position, -1);
      }
    }
    else if (character == '>')
    {
      if (cursor_position != text.end())
      {
        std::advance(cursor_position, 1);
      }
    }
    else if (character == '@')
    {
      if (cursor_position != text.begin())
      {
        text.erase(std::prev(cursor_position));
      }
    }
    else if (character == '$')
    {
      if (is_insertion_mode)
      {
        is_insertion_mode = false;
      }
      else
      {
        is_insertion_mode = true;
      }
    }
  }
  return std::string(text.begin(), text.end());
}
