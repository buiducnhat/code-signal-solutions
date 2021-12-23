int solution(int a, int b, int n) {
    return n*a*b + (n-1)*n/2*(a+b) + (n-1)*n*(2*n-1)/6;
}
