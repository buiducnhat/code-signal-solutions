vector<int> solution(vector<int> inputArray, int elemToReplace, int substitutionElem) {
    for (auto &i : inputArray) {
        if (i == elemToReplace) {
            i = substitutionElem;
        }
    }
    
    return inputArray;
}
