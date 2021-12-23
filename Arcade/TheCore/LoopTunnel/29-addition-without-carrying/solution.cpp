int solution(int a, int b) {
    int res=0, i=1;
    while (a | b) {
        res += (a%10 + b%10)%10 * i;
        a/=10, b/=10, i*=10;
    }
    return res;
}
