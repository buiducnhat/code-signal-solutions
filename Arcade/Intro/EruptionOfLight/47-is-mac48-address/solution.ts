function solution(inputString: string): boolean {
  const part = inputString.split("-");

  if (part.length !== 6) return false;

  const validChars = "0123456789ABCDEF";
  return part.every((num) => num.length === 2 && num.split("").every((i) => validChars.includes(i)));
}
