function solution(solution, args) {
  var argumentVariants = args.join('|');
  var re = new RegExp("(\\W)\\$?("+argumentVariants+")(?=\\W)", "g");
  var sub = "$1$$$2";
  return solution.replace(re, sub);
}