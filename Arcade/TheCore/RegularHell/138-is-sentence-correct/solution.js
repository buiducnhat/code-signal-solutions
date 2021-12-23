function solution(sentence) {
  var re = /^[A-Z][^!.?]*[\.|!|\?]$/;
  return re.test(sentence);
}
