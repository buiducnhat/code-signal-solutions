//4 hướng
vector<pair<int, int>> direction =
{
    { 1, 0 },//bot
    { 0, 1 },//right
    {-1, 0 },//up
    { 0,-1 }//left
};

int FindLines(vector<vector<char>> &field)
{
    vector<vector<bool>> used(field.size(), vector<bool>(field[0].size()));
    vector<vector<pair<int, int>>> lines;
    
    char ball = '-';
    
    // VERTICAL
    //duyệt theo từng cột
    for(int i=0; i<9; i++)
    {       
        for(int j=0; j<9; j++)
        {
            if(field[j][i] != '.')
            {                
                if(used[j][i]) continue;
                vector<pair<int, int>> line;

                ball = field[j][i];
                int k = j;
                
                while(k < 9 && field[k][i] == ball)
                {
                    //tìm số bóng liên tiếp
                    line.push_back({k,i});
                    k++;
                }
                if(line.size() >= 5)
                {
                    lines.push_back(line);
                    
                    while(!line.empty())
                    {
                        used[line.back().first][line.back().second] = 1;                        
                        line.pop_back();
                    }
                }
            }
        }
    }
        
    // đường chéo '/'
    
    for(int i=8; i>=4; i--)
    {        
        for(int j=0; j<5 ; j++)
        {            
            if(field[i][j] != '.')
            {                
                if(used[i][j]) continue;
                    
                vector<pair<int, int>> line;
                ball = field[i][j];
                
                int y = i, 
                    x = j;
                //tìm số bóng liên tiếp
                while(y >= 0 && x < 9 && field[y][x] == ball)
                {
                    line.push_back({y, x});
                    y--;
                    x++;
                }
                
                if(line.size() >= 5)
                {
                    lines.push_back(line);
                    
                    while(!line.empty())
                    {
                        used[line.back().first][line.back().second] = 1;
                        line.pop_back();
                    }
                }
            }
        }
    }    
    
    // đường chéo '\'
    for(int i=0; i<5; i++)
    {        
        for(int j=0; j<5; j++)
        {     
            if(field[i][j] != '.')
            {                
                if(used[i][j]) continue;
                    
                vector<pair<int, int>> line;
                ball = field[i][j];
                
                int y = i, 
                    x = j;
                
                //tìm dãy bóng liên tiếp
                while(y < 9 && x < 9 && field[y][x] == ball)
                {
                    line.push_back({y, x});
                    y++;
                    x++;
                }
                
                if(line.size() >= 5)
                {
                    lines.push_back(line);
                    
                    while(!line.empty())
                    {
                        used[line.back().first][line.back().second] = 1;
                        line.pop_back();
                    }
                }
            }
        }
    }        
    
    // 
    //duyệt theo hàng
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<5; )
        {
            if(field[i][j] != '.')
            {
                ball = field[i][j];
                vector<pair<int, int>> line;
                
                while(j < 9 && field[i][j] == ball)
                {
                    line.push_back({i, j});
                    j++;
                }
                if(line.size() >= 5)
                {
                    lines.push_back(line);
                    while(!line.empty())
                    {
                        used[line.back().first][line.back().second] = 1;                        
                        line.pop_back();
                    }
                }
            }
            else j++;
        }
    }
    
    //nếu cái vị trí nào đã kết hợp được 1 succesful move thì xóa 
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(used[i][j])
            {
                field[i][j] = '.';
            }
        }
    }
    
    int totalBalls = 0;
    
    for(auto L : lines)
    {
        totalBalls += L.size();
    }
    return (lines.size() == 0) ? 0 : (lines.size() + totalBalls)-1;//công thức tính điểm đề bài cho
}

//check clear path
bool IsClear(vector<vector<char>> &field, pair<int, int> start)
{
    int valid = 0;

    for(auto d : direction)
    {
        int y = start.first + d.first;
        int x = start.second + d.second;

        if(y<0 || x<0 || y>=9 || x>=9) continue;
        else if(field[y][x] != '.') continue;

        valid++;
    }
    return (valid > 0);    
}


int solution(vector<vector<char>> field, vector<vector<int>> clicks, vector<char> newBalls, vector<vector<int>> newBallPos) 
{
    int score = 0;
    int newIndex = 0;
    char ball = '-';
    
    for(int i=1; i<clicks.size(); i++)
    {
        //kiểm tra từng cặp click
        pair<int,int> from = {clicks[i-1][0], clicks[i-1][1]}, 
                        to = {clicks[i][0],   clicks[i][1]};
        
        if(field[from.first][from.second] != '.' && field[to.first][to.second] == '.')//check corect click
        {
            bool clear = IsClear(field, to);                       
            if(clear)
            {              
                //if clear move the ball  
                char ball = field[from.first][from.second];

                field[from.first][from.second] = '.';
                field[to.first][to.second] = ball;                 
                i++;
            }
        }
        
        int points = FindLines(field);         

        if(points > 0) score += points;
        else
        {
            //nếu mỗi lần chuyển bóng mà không có điểm thì sẽ thêm 3 quả bóng mới
            for(int j=0; j<3 && newIndex < newBalls.size(); j++)
            {
                field[newBallPos[newIndex][0]][newBallPos[newIndex][1]] = newBalls[newIndex];
                newIndex++;
            }            
        }               
    }
    score += FindLines(field);           
    return score;
}