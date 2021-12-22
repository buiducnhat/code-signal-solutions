bool solution(bool young, bool beautiful, bool loved) {
    return (young && beautiful && !loved) || ((!young || !beautiful) && loved);
}
