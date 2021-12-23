int calSumAtPos(vector<int> a, int pos) {
  int sum = 0;
  for (int i = 0; i < a.size(); i++) {
    sum += abs(a[pos] - a[i]);
  }
  return sum;
}

int solution(vector<int> a) {
    int minSum = INT_MAX, pos = 0;
    for (int i = 0; i < a.size(); i++) {
      int curSum = calSumAtPos(a, i);
      pos = curSum < minSum ? i : pos;
      minSum = min(minSum, curSum);
    }
    return a[pos];
}
