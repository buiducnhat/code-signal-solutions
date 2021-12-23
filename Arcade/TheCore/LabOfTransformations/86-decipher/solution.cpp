string solution(string cipher) {
    string res = "";
    for (int i = 0; i < cipher.length(); i++) {
        int tmp = 0;
        while (tmp < 'a') {
            tmp = tmp*10 + cipher[i]-'0';
            i++;
        }
        i--;
        res += tmp;
    }
    return res;
}
