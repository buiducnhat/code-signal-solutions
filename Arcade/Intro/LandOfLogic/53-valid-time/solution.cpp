bool solution(string t) {
    regex r("(2[0-3]|[0-1][0-9]):[0-5][0-9]");
    return regex_match(t, r);
}
