
//hàm đổi màu các mặt
void triswap(char& a, char& b, char& c, bool direction) {
    char d = a;
    if (direction) {
        a = b;
        b = c;
        c = d;
    } else {
        a = c;
        c = b;
        b = d;
    }
}
void swapFaces(std::vector<std::vector<char>>& faces, int A, int a, int B, int b, int C, int c, bool direction) {
    triswap(faces[A][a], faces[B][b], faces[C][c], direction);
}
std::vector<std::vector<char>> solution(std::vector<char> faceColors, std::vector<std::string> moves) {
    std::vector<std::vector<char>> faces;
    for (const auto& color : faceColors) {
        faces.emplace_back(9, color);
    }
    std::reverse(moves.begin(), moves.end());
    for (const auto& move : moves) {
        bool dir = move.size() > 1;//kiểm tra hướng quay
        int i;
        switch (move[0] & ~32) {
            case 'U':
                i = 0;
                break;
            case 'L':
                i = 1;
                break;
            case 'R':
                i = 2;
                break;
            case 'B':
                i = 3;
                break;
        }
        //bộ 3 các mặt mỗi lần di chuyển
        int a[4][3] = {
            {2, 3, 0},//u
            {0, 1, 2},//l
            {1, 0, 3},//r
            {3, 2, 1},//b
        };
        if (islower(move[0])) {
            //đổi màu 3 mảnh ở tầng 2
            swapFaces(faces, a[i][0], 1, a[i][1], 6, a[i][2], 3, dir);
            swapFaces(faces, a[i][0], 5, a[i][1], 7, a[i][2], 2, dir);
            swapFaces(faces, a[i][0], 6, a[i][1], 3, a[i][2], 1, dir);
        }
        swapFaces(faces, a[i][0], 4, a[i][1], 8, a[i][2], 0, dir);//đổi màu viên ở đỉnh
    }
    return faces;
}
