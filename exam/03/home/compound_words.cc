// alternative provided by TA 鄧晉杰
std::vector<std::string> CompoundWords (long n, std::vector<std::string> Words)
{
  std::vector<std::string> compound_words;
  std::set<std::string> word_set;
  for (auto const &word : Words)
  {
    word_set.insert(word);
  }
  for (auto const &word : Words)
  {
    for (size_t middle {1}; middle != word.size(); ++middle)
    {
      if
      (
        (word_set.find(word.substr(0, middle)) != word_set.end())
        && (word_set.find(word.substr(middle)) != word_set.end())
      )
      {
        compound_words.push_back(word);
        break;
      }
    }
  }
  return compound_words;
}
