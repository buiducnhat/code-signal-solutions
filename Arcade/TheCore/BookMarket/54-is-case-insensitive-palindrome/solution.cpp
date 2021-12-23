bool solution(string s) {
    for (auto &c : s) c = tolower(c);
    int len = s.length();
    string first = s.substr(0, len/2);
    string second = s.substr(len/2 + (len&1));
    reverse(second.begin(), second.end());
    return first == second;
}
