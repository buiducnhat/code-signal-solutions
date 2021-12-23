bool solution(vector<int> length, vector<int> width, vector<int> height) {
    // array store boxes, boxes[i] stores [x,y,z]
    vector<vector<int>> boxes(length.size());
    for (int i = 0; i < length.size(); i++) {
        boxes[i] = {length[i], width[i], height[i]};
        // sort direction of each box
        sort(boxes[i].begin(), boxes[i].end());
    }
    // sort boxes base on the minimum edge of box
    sort(boxes.begin(), boxes.end(), [](vector<int> a, vector<int> b) {
       return a[0] < b[0]; 
    });
    for (int i = 0; i < length.size() - 1; i++) {
        for (int j = 0; j < 3; j++) {
            if (boxes[i][j] >= boxes[i+1][j]) {
                return false;
            }
        }
    }
    return true;
}
