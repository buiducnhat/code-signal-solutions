int solution(int min1, int min2_10, int min11, int s) {
    int total = 0;
    
    // Count min1
    if (s >= min1) {
        total++;
        s -= min1;
    }
    
    // Count min2_10
    total += s/min2_10 >= 9 ? 9 : s/min2_10;
    s = (s/min2_10 >= 9) ? s-min2_10*9 : s%min2_10;

    // Count min11
    total += total >= 10 ? s/min11 : 0;
    
    return total;
}
 
