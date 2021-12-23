bool checkIsSorted(vector<int> a) {
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] >= a[i+1]) {
            return false;
        }
    }
    return true;
}

bool solution(vector<int> a) {
    int pos = -1;
    
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] >= a[i+1]) {
            pos = i;
            break;
        }
    }
    auto tmp1 = a, tmp2 = a;
    tmp1.erase(tmp1.begin() + pos);
    tmp2.erase(tmp2.begin() + pos + 1);
    return (checkIsSorted(tmp1) || checkIsSorted(tmp2));
}
