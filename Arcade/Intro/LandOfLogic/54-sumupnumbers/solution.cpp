int solution(string s) {
    int sum = 0, len = s.length(), i = 0;
    
    while (i < len) {
        string tmp = "";
        while (isdigit(s[i])) {
            tmp.push_back(s[i]);
            i++;
        }
        if (tmp.length()){
            sum += stoi(tmp);
        }
        i++;
    }

    return sum;
}
