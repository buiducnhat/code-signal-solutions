string solution(string text) {
    int i = 0, len = text.length();
    string res = "";
    
    while (i < len) {
        string tmp = "";
        while (isalpha(text[i])){
            tmp.push_back(text[i]);
            i++;
        }
        res = tmp.length() > res.length() ? tmp : res;
        i++;
    }
    
    return res;
}
