function solution(arr: number[]): boolean {
    let middle = arr[Math.floor(arr.length/2)];
    if (arr.length % 2 == 0) {
        middle += arr[Math.floor(arr.length/2)-1];
    }
    return arr[0] === middle && arr[0] === arr[arr.length-1];
}
