int solution(std::vector<int> a) {
    int result=0;
    for(int i = 0; i < a.size(); i++)
        result += a[i] << (8*i);
    return result;
}
