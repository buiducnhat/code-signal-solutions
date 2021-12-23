int solution(int deposit, int rate, int threshold) {
    return ceil(log((float)threshold / deposit) / log(1 + (float)rate / 100));
}
