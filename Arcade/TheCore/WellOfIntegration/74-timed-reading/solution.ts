function solution(maxLength: number, text: string): number {
  return text.split(/[^a-zA-Z]/g).filter(word => word.length && word.length <= maxLength).length;
}
