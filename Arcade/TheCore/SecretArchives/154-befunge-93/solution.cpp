string solution(vector<string> p) {
    //lưu bước đi theo thứ tự phải, xuống, trái, lên
    const int DI[] = {0, -1, 0, 1};
    const int DJ[] = {1, 0, -1, 0};
    
    const int m = p.size(), n = p[0].size();// lưu kích thước mảng
    
    int i = 0, j = 0, d = 0;
    std::vector<int> stack;
    std::ostringstream out;
    
    auto Push = [&stack](int x) { stack.push_back(x); }; //hàm để thực hiện thao tác push
    
    //hàm thực hiện thao tác Pop
    auto Pop = [&stack]() {
        if (stack.empty()) return 0;
        int x = stack.back();
        stack.pop_back();
        return x;
    };
    
    //hàm thực hiện thao tác Top, lấy phần tử đầu mảng
    auto Top = [&stack]() { return stack.empty() ? 0 : stack.back(); };
    
    //hàm thực hiện di chuyển
    auto Step = [&i, &j, &d, m, n, DI, DJ]() {
        i = (i + DI[d] + m) % m;
        j = (j + DJ[d] + n) % n;
    };
    
    bool string_mode = false;
    for (int cmd = 0; cmd < 100000 && out.str().size() < 100; ++cmd) {
        if (string_mode) {
            if (p[i][j] == '"') string_mode = false;
            else Push(p[i][j]);
        } else if (isdigit(p[i][j])) {
            Push(p[i][j] - '0');
        } else switch (p[i][j]) {
            case '>': d = 0; break;
            case '<': d = 2; break;
            case 'v': d = 3; break;
            case '^': d = 1; break;
            case '#': Step(); break;
            case '_': d = (Pop() ? 2 : 0); break;
            case '|': d = (Pop() ? 1 : 3); break;
            case '+': { int a = Pop(), b = Pop(); Push(b + a); } break;
            case '-': { int a = Pop(), b = Pop(); Push(b - a); } break;
            case '*': { int a = Pop(), b = Pop(); Push(b * a); } break;
            case '/': { int a = Pop(), b = Pop(); Push(b / a); } break;
            case '%': { int a = Pop(), b = Pop(); Push(b % a); } break;
            case '!': Push(!Pop()); break;
            case '`': { int a = Pop(), b = Pop(); Push(b > a ? 1 : 0); } break;
            case ':': Push(Top()); break;
            case '\\': { int a = Pop(), b = Pop(); Push(a); Push(b); } break;
            case '$': Pop(); break;
            case '.': out << Pop() << " "; break;
            case ',': out << (char) Pop(); break;
            case '"': string_mode = true; break;
            case '@': goto hell;
        }
        Step();
    }
    hell:
    return out.str().substr(0, 100);
}