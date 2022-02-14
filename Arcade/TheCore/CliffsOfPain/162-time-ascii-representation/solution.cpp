//xác định số 
int RecogDigit(const vector<vector<char>> &dtime, int x)
{
    if (dtime[0][x+1] == '.') return 1;
    if (dtime[0][x+2] == '.') return 4;
    if (dtime[16][x+1] == '.') return 7;
    if (dtime[1][x+1] == '.') return dtime[15][x+1] == '.' ? 3 : 2;
    if (dtime[15][x+1] == '.') return dtime[1][x+3] == '.' ? 5 : 9;
    if (dtime[1][x+3] == '.') return 6;
    return dtime[8][x+2] == '.' ? 0 : 8;
}
std::vector<std::vector<char>> solution(std::vector<std::vector<char>> dtime) {
    double dx, dy, ang, ha, hb, ma, mb, d;
    int hour = (RecogDigit(dtime, 0) * 10 + RecogDigit(dtime, 4)) % 12;
    int min = RecogDigit(dtime, 9) * 10 + RecogDigit(dtime, 13);
    printf("%02d:%02d\n", hour, min);
    
    //góc kim giờ
    ang = 1.5 * M_PI - 2 * M_PI * (hour + min / 60.0) / 12;
    ha = sin(ang) * 8.5, hb = cos(ang) * 8.5;
    
    //góc kim phút
    ang = 1.5 * M_PI - 2 * M_PI * min / 60;
    ma = sin(ang) * 8.5, mb = cos(ang) * 8.5;
    
    vector<vector<char>> out(17, vector<char>(17, '.'));
    const double epsilon = sqrt(0.49999999);//sai số
    
    //duyệt từng ô, * nếu thỏa mãn điều kiện
    for (int y = 0; y < 17; ++y)
    {
        for (int x = 0; x < 17; ++x)
        {
            //vì đồng hồ là 17x17, bán kính sẽ là 8.5
            // dx, dy : -8->8
            dx = x - 8;
            dy = y - 8;
            d = sqrt(dx*dx + dy*dy) - 8.5;

            // bỏ qua các ô nằm ngoài viền đồng hồ
            if (d > epsilon) continue;

            // viền đồng hồ
            if (fabs(d) < epsilon)
                out[y][x] = '*';
            
            // kim giờ
            if (fabs(ha*dx + hb*dy) / 8.5 < epsilon)
                if ((dy*ha - dx*hb) / (8.5*8.5) >= 0)
                    out[y][x] = '*';
            
            // kim phút
            if (fabs(ma*dx + mb*dy) / 8.5 < epsilon)
                if ((dy*ma - dx*mb) / (8.5*8.5) >= 0)
                    out[y][x] = '*';
        }
    }
    return out;
}
