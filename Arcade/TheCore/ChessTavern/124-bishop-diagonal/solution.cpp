vector<string> solution(string b1, string b2) {
    if (b1[0] > b2[0]) swap(b1, b2);
    bool isSameDiagonal = (abs(b1[0]-b2[0]) == abs(b1[1] - b2[1]));
    if (!isSameDiagonal) {
        return {b1, b2};
    }
    bool isUp = b1[1] < b2[1];
    if (isUp) {
        while (b1[0] > 'a' && b1[1] > '1') {
            b1[0]--;
            b1[1]--;
        }
        while (b2[0] < 'h' && b2[1] < '8') {
            b2[0]++;
            b2[1]++;
        }
    } else {
        while (b1[0] > 'a' && b1[1] < '8') {
            b1[0]--;
            b1[1]++;
        }
        while (b2[0] < 'h' && b2[1] > '1') {
            b2[0]++;
            b2[1]--;
        }
    }
    return {b1, b2};
}
