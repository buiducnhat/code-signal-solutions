function solution(inputArray: number[], l: number, r: number): number[] {
    return inputArray.slice(0, l).concat(inputArray.slice(r+1));
}
