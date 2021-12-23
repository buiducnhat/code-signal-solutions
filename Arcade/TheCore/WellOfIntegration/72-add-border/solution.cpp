vector<string> solution(vector<string> picture) {
    int rowNum = picture.size(), colNum = picture[0].size();
    
    string boundBorder = string(colNum+2, '*');
    
    for (int i = 0; i < rowNum; ++i ) {
        picture[i] = "*" + picture[i] + "*";
    }
    picture.insert(picture.begin(), boundBorder);
    picture.push_back(boundBorder);
        
    return picture;
}
