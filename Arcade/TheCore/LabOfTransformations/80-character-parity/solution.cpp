string solution(char symbol) {
    if (isdigit(symbol)) {
        return (symbol-'0')&1 ? "odd" : "even";
    }
    return "not a digit";
}
