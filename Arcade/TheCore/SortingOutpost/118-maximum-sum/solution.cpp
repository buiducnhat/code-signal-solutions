// Solution 1: Brute force (find all permutations)
// int solution(vector<int> a, vector<vector<int>> q) {
//     int res = 0;
//     sort(a.begin(), a.end());
//     do {
//         int cur = 0;
//         for (int i = 0; i < q.size(); i++) {
//             cur += accumulate(a.begin() + q[i][0], a.begin() + q[i][1] + 1, 0);
//         }
//         res = max(res, cur);
//     } while (next_permutation(a.begin(), a.end()));
    
//     return res;
// }

// Solution 2: Find the most frequency index
int solution(vector<int> a, vector<vector<int>> q) {
    vector<int> count(a.size());
    for (vector<int>& p: q) {   
        for (int i = p[0]; i < p[1]+1; i++) {
            count[i]++;
        }
    }
    sort(count.begin(), count.end());
    sort(a.begin(), a.end());
    int res = 0;
    for (int i = 0; i < a.size(); i++) {        
        res += a[i] * count[i];
    }
    return res;
}