int solution(string a, string b) {
    int count_b[26] = {0}, count_a[26]={0};
    for (auto c : a) count_a[c-'a']++;
    for (auto c : b) count_b[c-'a']++;
    int res = INT_MAX;
    for (auto c : a) {
        res = min(res, count_b[c-'a']/count_a[c-'a']);
    }        
    return res;
}
