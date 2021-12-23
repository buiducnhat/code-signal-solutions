function solution(arr: number[]): number[] {
  if (arr.length % 2 == 0) {
    let midPositions = [
      Math.floor(arr.length / 2 - 1),
      Math.floor(arr.length / 2),
    ];
    arr.splice(midPositions[0], 2, arr[midPositions[0]] + arr[midPositions[1]]);
  }
  return arr;
}
