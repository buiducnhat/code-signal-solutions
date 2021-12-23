string solution(string code) {
    string res = "";
    for (int i = 0; i < code.length(); i+=8) {
        res += stoi(code.substr(i, 8), 0, 2);
    }
    
    return res;
}
