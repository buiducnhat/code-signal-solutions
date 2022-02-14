typedef std::bitset<10> Row;

int clear_rows(auto &board) {
    int cleared_rows = 0;
    for (int i = board.size() - 1; i >= 0; --i) {
        if (!board[i].all()) continue;
        ++cleared_rows;
        board.erase(board.begin() + i);
        board.push_back(Row());
    }
    return cleared_rows;
}

// flip and binarize
auto compress(const auto &piece) {
    const int H = piece.size(), W = piece.front().size();
    std::vector<std::vector<bool>> b(H, std::vector<bool>(W));
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            b[y][x] = (piece[H-y-1][x] == '#');
        }
    }
    return b;
}

auto rotate(const auto &b) {
    const int H = b.front().size(), W = b.size();
    std::vector<std::vector<bool>> rotated(H, std::vector<bool>(W));
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            rotated[y][x] = b[x][H-y-1];
        }
    }
    return rotated;
}
//tính giá trị
int value(const auto &board, const auto &b, const int x, int &best_y) {
    const int H = b.size(), W = b.front().size();
    
    int max_value = -1;
    if (x+W > board.front().size()) return max_value;
    
    for (int y = board.size() - H; y >= 0; --y) {
        bool fits = true;
        //kiểm tra vị trí trống
        for (int dy = 0; dy < H && fits; ++dy) {
            for (int dx = 0; dx < W && fits; ++dx) {
                const int y2 = y+dy, x2 = x+dx;
                fits &= !board[y2][x2] || !b[dy][dx];
            }
        }
        if (!fits) break;
        int v = 0;
        //bước tính giá trị
        for (int dy = 0; dy < H; ++dy) {
            for (int x2 = 0; x2 < board.front().size(); ++x2) {
                v += board[y+dy][x2];
            }
        }
        if (v >= max_value) {
            max_value = v;
            best_y = y;
        }
    }
    return max_value;
}

void place(auto &board, const auto &best_ro, const int best_x, const int best_y) {
    const int H = best_ro.size(), W = best_ro.front().size();
    for (int dy = 0; dy < H; ++dy) {
        for (int dx = 0; dx < W; ++dx) {
            if (best_ro[dy][dx]) board[best_y+dy][best_x+dx] = 1;
        }
    }
}   

int solution(std::vector<std::vector<std::vector<char>>> pieces) {
    int points = 0;
    
    std::vector<Row> board(20);
    for (const auto &piece : pieces) {
        auto b = compress(piece);
        int max_value = -1, best_x = -1, best_y = -1;
        auto best_ro = b;
        //each rotate
        for (int i = 0; i < 4; ++i) {
            for (int x = 0; x < 10; ++x) {
                int y = -1;
                const int v = value(board, b, x, y);
                if (v > max_value) {
                    max_value = v;
                    best_ro = b;
                    best_x = x;
                    best_y = y;
                }
            }
            b = rotate(b);
        }
        
        place(board, best_ro, best_x, best_y);
        
        points += clear_rows(board);
    }
    
    return points;
}