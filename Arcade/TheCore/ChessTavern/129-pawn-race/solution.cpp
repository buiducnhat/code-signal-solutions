std::string solution(std::string white, std::string black, char toMove) {
    if (white[0] == black[0] && white[1] < black[1]) return "draw";
    if (white[1] == '8') return "white";
    if (black[1] == '1') return "black";
    if (abs(white[0]-black[0]) == 1 && white[1] + 1 == black[1])
        return toMove == 'w' ? "white" : "black";
        
    string best = toMove == 'w' ? "black" : "white";
    
    if (toMove == 'w') {
        ++white[1];
        best = max(best, solution(white, black, 'b'));
        if (++white[1] == '4')
            best = max(best, solution(white, black, 'b'));
    }
    else {
        --black[1];
        best = min(best, solution(white, black, 'w'));        
        if (--black[1] == '5')
            best = min(best, solution(white, black, 'w'));
    }

    return best;
}
