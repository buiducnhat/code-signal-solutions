bool solution(string s) {
    for (int i = 0; i < s.length() - 1; i++) {
        for (int j = i + 1; j < s.length(); j++) {
            if (s[i]  s[j]){
                return false;
            }
        }
    }
    return true;
}
