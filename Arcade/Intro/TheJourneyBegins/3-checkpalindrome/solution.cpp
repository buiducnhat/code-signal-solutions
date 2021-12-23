bool solution(string inputString) {
    deque<char> q;
    int i = -1, len = inputString.size();
    while (i++ < len - 1) {
        q.push_back(inputString[i]);
    }
    
    while (q.size() > 1) {
        if (q.front() != q.back()) {
            return false;
        }
        q.pop_back();
        q.pop_front();
    }
    return true;
}
