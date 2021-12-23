
int ways(int n, int m, int x, int y) {
    if (n < x || m < y) return 0;
    return (n - x + 1) * (m - y + 1);
}

int times(int n, int m, int x, int y) {
  return (ways(n, m, x, y) + ways(m, n, x, y)) * 8;
}

int solution(int n, int m) {
    return (
        times(n, m, 2, 3) +
        times(n, m, 3, 3) +
        times(n, m, 2, 4) +
        times(n, m, 3, 4)
    );
}