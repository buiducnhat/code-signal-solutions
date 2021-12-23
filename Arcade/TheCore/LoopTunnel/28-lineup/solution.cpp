int solution(string commands) {
    int count=0;
    bool same = true;
    for (int i = 0, len = commands.length(); i < len; i++) {
        if (commands[i] != 'A') same=!same;
        count += same;
    }
    return count;
}
