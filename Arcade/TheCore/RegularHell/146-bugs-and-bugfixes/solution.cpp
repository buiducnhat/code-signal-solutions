int solution(std::string rules) {
  std::regex pattern("(\\d*)d(\\d+)([+-]\\d+)*");

  std::sregex_iterator it(rules.cbegin(), rules.cend(), pattern);
  std::sregex_iterator end;

  int res = 0;
  while (it != end) {
    int rolls = it->str(1).empty() ? 1 : std::stoi(it->str(1));
    int dieType = std::stoi(it->str(2));
    int formulaMax = rolls * dieType;

    if (!it->str(3).empty()) {
      if (it->str(3)[0] == '-') {
        formulaMax -= std::stoi(it->str(3).substr(1));
      }
      else {
        formulaMax += std::stoi(it->str(3).substr(1));
      }
    }

    res += formulaMax;
    it++;
  }

  return res;
}