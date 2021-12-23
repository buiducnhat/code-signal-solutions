bool solution(int s, vector<vector<string> > a){
    s = (s + 1) / 2;
    for (const auto i : { 0, 1 }) {
        auto field = [&](int x, int y) { return i ? a[y][x] : a[x][y]; };

        for (int y = s; y < size(a); ++y) {
            int f = s - 1;

            for (int x = size(a) - 1, a = 0; x >= s - 1; --x)
                if (field(y, x) == "#")
                    ++a;
                else if (a) {
                    if (f < 0 || to_string(a) != field(y, f))
                        return false;
                    a = 0;
                    --f;
                }

            while (f >= 0)
                if (field(y, f--) != "-")
                    return false;
        }
    }

    return true;
}
