function solution(a: number): number {
    return parseInt(a.toString(2).split('').reverse().join(''), 2);
}
