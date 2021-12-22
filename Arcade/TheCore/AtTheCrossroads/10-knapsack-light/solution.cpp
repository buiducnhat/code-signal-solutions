int solution(int value1, int weight1, int value2, int weight2, int maxW) {
    if (maxW >= (weight1 + weight2)) {
        return value1 + value2;
    } else {
        return maxW >= weight1 ? maxW >= weight2 ? max(value1, value2) : value1 : maxW >= weight2 ? value2 : 0;
    }
}
