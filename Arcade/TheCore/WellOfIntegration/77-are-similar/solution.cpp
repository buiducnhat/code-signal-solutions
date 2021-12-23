bool solution(vector<int> a, vector<int> b) {    
    int first = 0, second = 0, count = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            count++;
            if (count == 1) {
                first = i;
            } else if (count == 2) {
                second = i;
            } else {
                return false;
            }
        }
    }
    
    if (a[first] != b[second] || a[second] != b[first]) {
        return false;
    }
    
    return true;
}
