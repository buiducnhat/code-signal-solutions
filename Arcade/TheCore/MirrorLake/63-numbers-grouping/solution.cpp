int solution(vector<int> a) {
    transform(a.begin(), a.end(), a.begin(), [](int num){
        return (num-1)/10000;
    });
    return set<int>(a.begin(), a.end()).size() + a.size();
}
