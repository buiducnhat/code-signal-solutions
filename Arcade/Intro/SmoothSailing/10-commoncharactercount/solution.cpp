int solution(string s1, string s2) {
    vector<int> count1(128), count2(128);
    
    for(int i = 0; i < s1.length(); i++) {
        count1[s1[i]]++;
    }
    for(int i = 0; i < s2.length(); i++) {
        count2[s2[i]]++;
    }
    
    int res = 0;
    for(int i = 0; i < count1.size(); i++) {
        res += min(count1[i], count2[i]);
    }
    return res;
}
