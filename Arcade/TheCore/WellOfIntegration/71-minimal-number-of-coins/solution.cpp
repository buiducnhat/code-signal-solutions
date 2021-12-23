int solution(vector<int> coins, int price) {
    int res = 0, i = coins.size();
    while (i-- > 0 && price) {
        res += price/coins[i];
        price = price%coins[i];
    }
    return res;
}
