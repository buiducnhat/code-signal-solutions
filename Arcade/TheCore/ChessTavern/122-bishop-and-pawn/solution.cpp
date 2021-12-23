bool solution(string bishop, string pawn) {
    return bishop[0]-bishop[1] == pawn[0]-pawn[1] || bishop[0]+bishop[1] == pawn[0]+pawn[1] ;
}
