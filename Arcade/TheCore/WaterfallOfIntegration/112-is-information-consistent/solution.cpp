bool solution(vector<vector<int>> evidences) {
    for (int j = 0; j < evidences[0].size(); j++) {
        // Store if column [j] has guilty  and inocent witness
        // x[0] = guilty , x[1] = inocent
        bool x[2] = {false, false};
        for (int i = 0; i < evidences.size(); i++) {
            if (evidences[i][j] == 1) {
                x[0] = true;
            } else if (evidences[i][j] == -1) {
                x[1] = true;
            }
        }
        // If has both guilty  and inocent -> not consistent 
        if (x[0] == x[1] && x[0] == true) {
            return false;
        }
    }
    return true;
}
