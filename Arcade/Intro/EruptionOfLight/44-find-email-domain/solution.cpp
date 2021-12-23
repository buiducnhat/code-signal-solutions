string solution(string address) {
    int i = address.length();
    while (address[i--] != '@') {}
    return address.substr(i+2);
}
