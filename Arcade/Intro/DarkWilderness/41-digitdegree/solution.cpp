int solution(int n) {
    int count = 0;
    while (n > 9) {
        int sum = 0;
        while (n){
            sum += n % 10;
            n /= 10;
        }
        n = sum;
        count++;
    }
    return count;
}
