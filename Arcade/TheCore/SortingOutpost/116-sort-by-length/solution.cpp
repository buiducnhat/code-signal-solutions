vector<string> solution(vector<string> a) {
    int len = a.size();
    int count = 0;
    do {
      count = 0;
      for (int i = 0; i < len - 1; i++) {
        if(a[i].length() > a[i+1].length()) {
          swap(a[i], a[i+1]);
          count++;
        }
      }
    } while (count>0);
    return a;
}
