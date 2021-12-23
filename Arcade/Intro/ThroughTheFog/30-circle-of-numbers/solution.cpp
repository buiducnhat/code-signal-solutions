int solution(int n, int firstNumber) {
    return firstNumber < n/2 ? firstNumber + n/2 : firstNumber - n/2;
}
