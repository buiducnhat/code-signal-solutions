vector<int> solution(vector<int> shuffled) {
    int sum = accumulate(shuffled.begin(), shuffled.end(), 0);
    auto pos = find(shuffled.begin(), shuffled.end(), sum/2);
    shuffled.erase(pos);
    sort(begin(shuffled), end(shuffled));
    return shuffled;
}
