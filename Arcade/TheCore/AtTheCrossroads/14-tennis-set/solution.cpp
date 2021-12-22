bool solution(int score1, int score2) {
    if (score1 < score2) swap(score1, score2);
    int h = score1 - score2;
    return (score1==6 && h >= 2) || (score1==7 && h<=2 && h>=1);
}
