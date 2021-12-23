string solution(string note) {
    for (auto &c:note) {
        if (isdigit(c)){
            c = c-'0'+'a';
        } else if ('a' <= c && c <= 'j') {
            c = c - 'a' + '0';
        }
    }
    return note;
}
