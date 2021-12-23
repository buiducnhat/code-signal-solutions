function solution(pairOfLines) {
  var re = /.*(.{3})\t.*(.{3})/gm;
  var match = re.exec(pairOfLines);
  return match[1] == match[2];
}
