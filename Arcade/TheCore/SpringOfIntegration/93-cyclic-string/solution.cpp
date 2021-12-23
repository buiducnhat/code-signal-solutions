int solution(std::string s) {
    for (int i = 1;; i++) {
        bool ok = true;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] != s[j % i]) {
                ok = false;
                break;
            }
        }
        if (ok)
            return i;
    }
}
