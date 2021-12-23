string solution(string startTag) {
    int i = 0;
    while (startTag[i] != ' ' && startTag[i] != '>'){
        i++;
    }
    string tagName = startTag.substr(1, i - 1);
    return "</" + tagName + ">";
}
