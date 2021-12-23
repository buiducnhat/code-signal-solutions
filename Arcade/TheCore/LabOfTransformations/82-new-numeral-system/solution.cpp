vector<string> solution(char c) {
    vector<string> res;
    for (int i = 'A'; i <= 'A'+(c-'A')/2; i++) {
        string tmp = "";
        tmp += i;
        tmp+=" + ";
        tmp+=c-i+'A';
        res.push_back(tmp);
    }
    return res;
}
