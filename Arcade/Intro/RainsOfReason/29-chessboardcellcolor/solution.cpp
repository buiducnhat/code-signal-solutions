bool solution(string cell1, string cell2) {
    int x1 = cell1[0] - 'A' + 1, y1 = cell1[1] - '0', x2 = cell2[0] - 'A' + 1, y2 = cell2[1] - '0';
    return (((x1 + y1) & 1) == ((x2 + y2) & 1));
}
