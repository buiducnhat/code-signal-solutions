bool solution(int yourLeft, int yourRight, int friendsLeft, int friendsRight) {
    return (yourLeft == friendsLeft || yourLeft == friendsRight) && (yourLeft + yourRight) == friendsLeft + friendsRight;
}
