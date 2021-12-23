bool solution(string name) {
    if (!isalpha(name[0]) && name[0] != '_') {
        return false;
    }
    for (auto c : name) {
        if (!isalpha(c) && !isdigit(c) && c != '_') {
            return false;
        }
    }
    return true;
}
