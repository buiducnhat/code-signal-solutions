int solution(int upSpeed, int downSpeed, int desiredHeight) {
    if (upSpeed >= desiredHeight) {
        return 1;
    }
    return ceil((float)(desiredHeight-upSpeed) / (upSpeed - downSpeed)) + 1;
}
