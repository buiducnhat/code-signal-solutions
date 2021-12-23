bool solution(string s, int l, int r) {
    // Thử chia thanh nhièu dòng, mỗi dòng i ký tự
    for(int i = l; i <= r; i++){
        // Kiểm tra chia hết
        if((s.length()+1) % (i+1) == 0){
            bool found = true;
            // Thử từng dòng xem ký tự cuối của phải dấu cách không
            for(int j = i; j < s.length(); j+=i+1){
                if(s[j] != ' '){
                    found = false;
                    break;
                }
            }
            if(found) {
                return true;
            }
        }
    }
    return false;
}
