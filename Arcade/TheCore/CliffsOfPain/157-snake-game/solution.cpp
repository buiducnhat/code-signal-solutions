const int L = 0, R = 1, U = 2, D = 3;
const vector<pair<int,int>> DIRECTIONS = {{0,-1}, {0,1}, {-1,0}, {1,0}};
const vector<vector<int>> ROTATIONS = {{D,U,L,R},{U,D,R,L}};
const vector<char> HEADS = {'<', '>', '^', 'v'};

void find_head(std::vector<std::vector<char>>& game, pair<int, int>& head, int& d ) {
    for (int i = 0; i < game.size(); ++i) {
        for (int j = 0; j < game[i].size(); ++j) {
            if (game[i][j] != '.' && game[i][j] != '*') {
                d = find(HEADS.begin(), HEADS.end(), game[i][j]) - HEADS.begin();
                head = {i, j};
                game[i][j] = '.';
                return;
            }
        }
    }    
}

bool find_body(std::vector<std::vector<char>>& game, list<pair<int, int>>& snake, int d)
{
    bool result = false;
    int i = snake.back().first, j = snake.back().second;
    //go up
    if ((d == -1 || d == U) && (i + 1) < game.size() && game[i + 1][j] == '*') {
        snake.push_back({i + 1, j});        
        result = true;
    }
    //go down
    if ((d == -1 || d == D) && i > 0 && game[i - 1][j] == '*') {
        snake.push_back({i - 1, j});
        result = true;
    }
    //go left
    if ((d == -1 || d == L) && (j + 1) < game[i].size() && game[i][j + 1] == '*') {
        snake.push_back({i, j + 1});
        result = true;
    }
    //go eight+
    if ((d == -1 || d == R) && j > 0 && game[i][j - 1] == '*') {
        snake.push_back({i, j - 1});
        result = true;
    }
    game[snake.back().first][snake.back().second] = '.';
    return result;
}

std::vector<std::vector<char>> solution(std::vector<std::vector<char>> game, std::string commands)
{    
    list<pair<int, int>> snake = {{0,0}};
    int d;
    find_head(game, *(snake.begin()), d);//find head
    find_body(game, snake, d);//find body
    while (find_body(game, snake, -1));    
    bool dead = false;
    for (char c : commands) {        
        if (c == 'F') {//go foward
            //i, j for next move
            int i = snake.front().first + DIRECTIONS[d].first;
            int j = snake.front().second + DIRECTIONS[d].second;
            //if meet the border -> dead
            if (i < 0 || i >= game.size() || j < 0 || j >= game[i].size()) {
                dead = true;
                break;
            }
            pair<int, int> segment = {i,j};
            //if meet the body -> dead
            auto itr = find(snake.begin(), snake.end(), segment);
            if (itr != snake.end() && *itr != snake.back()) {
                dead = true;
                break;
            }
            //update position of snake
            snake.push_front(segment);
            snake.pop_back();            
        } else {
            d = ROTATIONS[c == 'R'][d];            
        }
        
    }       
    //fill the snake body
    for (auto & item: snake) {
        game[item.first][item.second] = dead ? 'X' : '*';
    }
    //fill the head
    if (!dead) {
        game[snake.front().first][snake.front().second] = HEADS[d]; 
    }    
    return game;
}