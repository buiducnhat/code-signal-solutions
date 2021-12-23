int solution(int k) {
    int o = (k+1)/2;
    int oddSum = o*(2*o-1)*(2*o+1)/3;
    cout << oddSum;
    return -(2*oddSum - k*(k+1)*(2*k+1)/6); 
}
