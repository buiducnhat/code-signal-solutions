bool isOk(string s1, string s2, string res) {
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i]!=res[i] && s2[i]!=res[i]){
            return false;
        }
    }
    return true;
}

int solution(vector<string> a, string result) {
    int count = 0;
    for (int i = 0; i < a.size()-1; i++) {
        for (int j = i+1; j < a.size(); j++) {
            if (isOk(a[i], a[j], result)) {
                count++;
            }
        }
    }
    return count;
}
