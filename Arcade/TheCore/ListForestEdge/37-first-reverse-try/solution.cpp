vector<int> solution(vector<int> arr) {
    int size = arr.size();
    if (size == 0) { return arr; };
    int tmp = arr[0]; 
    arr[0] = arr[size-1];
    arr[size-1] = tmp;
    return arr;
}
