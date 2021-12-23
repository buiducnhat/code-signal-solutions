int solution(int n) {
    int count = 0;
    for(int i = 1; i < n; i++){
        int sum = i, j = 1;
        while(sum < n){
            sum = sum + i + j;
            j++;
        }
        if(sum == n) count++;
    }
    return count;
}
