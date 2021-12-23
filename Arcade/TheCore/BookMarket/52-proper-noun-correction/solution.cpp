string solution(string noun) {
    for (auto &c : noun) c = tolower(c);
    noun[0] = toupper(noun[0]);
    return noun;
}
