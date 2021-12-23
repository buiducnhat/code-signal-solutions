int solution(vector<int> statues) {
    sort(statues.begin(), statues.end());
    
    int dist = statues.back() - statues.front();
    cout << dist;
    
    return dist - statues.size() + 1;
}
