struct Square{
    bool top, bottom, left, right;
};

typedef std::vector<std::vector<Square>> Fractal;

// quay theo chiều kim đồng hồ 90 với số lần "times"
auto clockwise90(const auto &original, const int times) {
    if (times == 0) return original;
    
    const int H = original.size(), W = original.front().size();
    auto copy = original;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            const auto &so = original[(H-1)-x][y];
            auto &sc = copy[y][x];
            sc.top = so.left;
            sc.bottom = so.right;
            sc.left = so.bottom;
            sc.right = so.top;
        }
    }
        
    return clockwise90(copy, times-1);
}

// biểu diễn kết quả
auto display(const auto &f) {
    const int H = f.size(), W = f.front().size();
    std::vector<std::vector<char>> a(H+1, std::vector<char>(2*W+1, ' '));
    for (int y = 0; y < H; ++y) {
        bool prev_top = false, prev_bottom = false;
        for (int x = 0; x < W; ++x) {
            const auto &s = f[y][x];
            if (s.top) {
                if (prev_top) a[y][2*x] = '_';
                a[y][2*x+1] = '_';
                prev_top = true;
            } else prev_top = false;
            if (s.bottom) {
                if (prev_bottom) a[y+1][2*x] = '_';
                a[y+1][2*x+1] = '_';
                prev_bottom = true;
            } else prev_bottom = false;
            if (s.left) a[y+1][2*x] = '|';
            if (s.right) a[y+1][2*x+2] = '|';
        }
    }
    return a;
};

// left.right<->right.left
// top.bottom<->bottom.top
// kết nối các mặt
void connect_sides(auto &f) {
    const int H = f.size(), W = f.front().size();
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (y>0 && f[y][x].top) f[y-1][x].bottom = true;
            if (y+1<H && f[y][x].bottom) f[y+1][x].top = true;
            if (x>0 && f[y][x].left) f[y][x-1].right = true;
            if (x+1<W && f[y][x].right) f[y][x+1].left = true;
        }
    }
}

std::vector<std::vector<char>> solution(int n) {
    Fractal prev = {{{1, 1, 0, 1}}};
    for (int i = 1; i < n; ++i) {
        const int H = prev.size(), W = prev.front().size();
        Fractal next(2*H+1, std::vector<Square>(2*W+1));
        
        // tạo 4 góc và đoạn nối
        const Fractal &top_left = prev;
        Fractal top_right, bottom_left, bottom_right;
        if (i & 1) {  // i lẻ
            bottom_left = bottom_right = clockwise90(prev, 1);
            top_right = clockwise90(bottom_left, 1);
            
            //đoạn nối
            next[H].front().left = true;
            next[H][W].bottom = true;
            next[H].back().right = true;
            
            
        } else {  // i chẵn 
            bottom_left = clockwise90(prev, 2);
            top_right = bottom_right = clockwise90(bottom_left, 1);
            
            //đoạn nối
            next.front()[W].top = true;
            next[H][W].right = true;
            next.back()[W].bottom = true;
        }
        
        // copy 4 góc vào next
        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) {
                next[y][x] = top_left[y][x];
                next[y][(W+1)+x] = top_right[y][x];
                next[(H+1)+y][x] = bottom_left[y][x];
                next[(H+1)+y][(W+1)+x] = bottom_right[y][x];
            }
        }
        
        prev = next;
        connect_sides(prev);
    }
    return display(prev);
}