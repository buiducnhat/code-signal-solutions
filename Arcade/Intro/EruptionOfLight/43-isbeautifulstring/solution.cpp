bool solution(string s) {
    int count[26] = {0};
    for (auto c : s) {
        count[c-'a']++;
    }
    return is_sorted(begin(count), end(count), greater<int>());
}
