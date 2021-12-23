int solution(vector<int> a) {
    auto calProduct = [](int x) {
        int product = 1;
        while(x) {
            product *= x%10;
            x/=10;
        }
        return product;
    };
    set<int> res;
    for (auto x : a){
        res.insert(calProduct(x));
    }
    return res.size();
}
