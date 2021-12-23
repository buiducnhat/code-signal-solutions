int solution(vector<int> a) {
    int c = 1;
    while (a.size() != 1) {
        vector<int> tmp;
        for (int i = 0; i < a.size()-1; i+=2) {
            if (c & 1) {
                tmp.push_back(a[i]+a[i+1]);
            } else {
                tmp.push_back(a[i]*a[i+1]);
            }
        }
        a = tmp;
        c++;
    }
    return a[0];
}
