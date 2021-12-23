bool solution(string s1, string s2) {
    int len = s1.length();
    int dict1[26], dict2[26];
    memset(dict1, -1, 26 * 4);
    memset(dict2, -1, 26 * 4);
    for (int i = 0; i < len; ++i) {
        dict1[s1[i] - 'a'] = s2[i] - 'a';
        dict2[s2[i] - 'a'] = s1[i] - 'a';
    }
    for (int i = 0; i < len; ++i) {
        if (dict2[dict1[s1[i] - 'a']] != s1[i] - 'a' || dict1[dict2[s2[i] - 'a']] != s2[i] - 'a') {
            return false;
        }
    }
    return true;
}
