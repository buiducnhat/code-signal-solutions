function solution(time: string): boolean {
    const result = time.match(/([0-1][0-9]|2[0-3]):[0-5][0-9]/gm);
    return !!result;
}
