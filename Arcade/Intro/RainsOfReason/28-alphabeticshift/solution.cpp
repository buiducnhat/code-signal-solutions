string solution(string inputString) {
    for (auto &c : inputString){
        if (c == 'z') {
            c = 'a';
        } else {
            c++;
        }
    }
    
    return inputString;
}
