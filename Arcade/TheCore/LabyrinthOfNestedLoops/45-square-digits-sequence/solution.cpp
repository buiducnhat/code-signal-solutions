int sumSquareDigits(int n) {
    int sum = 0;
    while (n) {
        sum += (n%10)*(n%10);
        n /= 10;
    }
    return sum;
}

int solution(int a0) {
    set<int> seq;
    while (seq.find(a0) == seq.end()) {
        seq.insert(a0);
        a0 = sumSquareDigits(a0);
    }
    return seq.size()+1;
}
