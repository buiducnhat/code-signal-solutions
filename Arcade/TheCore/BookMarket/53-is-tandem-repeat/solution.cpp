bool solution(string s) {
    int len = s.length();
    return s.substr(0, len/2) == s.substr(len/2);
}
